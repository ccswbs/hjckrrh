<?php

/**
 * @file
 * Contains FeedsExJsonPath.
 */

use Peekmo\JsonPath\JsonStore;

/**
 * Parses JSON via JSONPath.
 */
class FeedsExJsonPath extends FeedsExBase {

  /**
   * The JSONPath parser implementation.
   *
   * @var FeedsExJsonPathParserInterface
   */
  protected $parser;

  /**
   * {@inheritdoc}
   */
  protected function executeContext(FeedsSource $source, FeedsFetcherResult $fetcher_result) {
    $raw = $this->prepareRaw($fetcher_result);
    $parsed = FeedsExJsonUtility::decodeJsonArray($raw);
    $parsed = $this->getParser()->search($parsed, $this->config['context']['value']);
    if (!is_array($parsed) || empty($parsed)) {
      throw new RuntimeException(t('The context expression must return an object or array.'));
    }

    $state = $source->state(FEEDS_PARSE);
    if (!$state->total) {
      $state->total = count($parsed);
    }

    $start = (int) $state->pointer;
    $state->pointer = $start + $source->importer->getLimit();
    return array_slice($parsed, $start, $source->importer->getLimit());
  }

  /**
   * {@inheritdoc}
   */
  protected function cleanUp(FeedsSource $source, FeedsParserResult $result) {
    unset($this->parser);
    // Calculate progress.
    $state = $source->state(FEEDS_PARSE);
    $state->progress($state->total, $state->pointer);
  }

  /**
   * {@inheritdoc}
   */
  protected function executeSourceExpression($machine_name, $expression, $row) {
    $result = $this->getParser()->search($row, $expression);

    if (is_scalar($result)) {
      return $result;
    }

    // Return a single value if there's only one value.
    return count($result) === 1 ? reset($result) : $result;
  }

  /**
   * {@inheritdoc}
   */
  protected function validateExpression(&$expression) {
    $expression = trim($expression);

    // Try to validate if possible.
    if (!class_exists('Flow\JSONPath\JSONPathLexer')) {
      return;
    }

    try {
      // Use class as string for PHP 5.2 compat.
      $class = 'Flow\JSONPath\JSONPathLexer';
      $lexer = new $class($expression);
      $lexer->parseExpression();
    }
    catch (Exception $e) {
      return check_plain($e->getMessage());
    }
  }

  /**
   * {@inheritdoc}
   */
  protected function startErrorHandling() {
    // Clear the json errors from previous parsing.
    json_decode('{}');
  }

  /**
   * {@inheritdoc}
   */
  protected function getErrors() {
    if (!function_exists('json_last_error')) {
      return array();
    }

    if (!$error = json_last_error()) {
      return array();
    }

    $message = array(
      'message' => FeedsExJsonUtility::translateError($error),
      'variables' => array(),
      'severity' => WATCHDOG_ERROR,
    );

    return array($message);
  }

  /**
   * {@inheritdoc}
   */
  protected function loadLibrary() {
    if (!FeedsExJsonUtility::jsonPathParserInstalled()) {
      throw new RuntimeException(t('The JSONPath library is not installed.'));
    }
  }

  /**
   * Returns the JSONPath parser.
   *
   * @return FeedsExJsonPathParserInterface
   *   The JSONPath parser.
   */
  protected function getParser() {
    if (!isset($this->parser)) {
      if (class_exists('Flow\JSONPath\JSONPath')) {
        $this->parser = new FeedsExJsonPathParserFlow();
      }
      elseif (class_exists('Peekmo\JsonPath\JsonStore')) {
        $this->parser = new FeedsExJsonPathParserPeekmo();
      }
      elseif (function_exists('jsonPath')) {
        $this->parser = new FeedsExJsonPathParser();
      }
    }

    return $this->parser;
  }

}

/**
 * Normalizes various JSONPath implementations.
 */
interface FeedsExJsonPathParserInterface {

  /**
   * Searches an array via JSONPath.
   *
   * @param array $data
   *   The array to search.
   * @param string $expression
   *   The JSONPath expression.
   *
   * @return mixed
   *   The search results.
   */
  public function search(array $data, $expression);

}

/**
 * Wraps the standard JSONPath implementation.
 */
class FeedsExJsonPathParser implements FeedsExJsonPathParserInterface {

  /**
   * {@inheritdoc}
   */
  public function search(array $data, $expression) {
    return jsonPath($data, $expression);
  }

}

/**
 * Wraps the Flow JSONPath implementation.
 */
class FeedsExJsonPathParserFlow implements FeedsExJsonPathParserInterface {

  /**
   * {@inheritdoc}
   */
  public function search(array $data, $expression) {
    // Use class string so that PHP 5.2 doesn't complain.
    $class = 'Flow\JSONPath\JSONPath';
    $json_path = new $class($data);

    return $json_path->find($expression)->data();
  }

}

/**
 * Wraps the Peekmo JSONPath implementation.
 */
class FeedsExJsonPathParserPeekmo implements FeedsExJsonPathParserInterface {

  /**
   * {@inheritdoc}
   */
  public function search(array $data, $expression) {
    $store = new JsonStore();
    return $store->get($data, $expression);
  }

}

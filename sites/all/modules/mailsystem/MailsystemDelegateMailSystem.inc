<?php

/**
 * @file
 * Class for formatting and actually sending a message.
 */

/**
 * A mailsystem delegate implementation that forwards to another implementation.
 */
class MailsystemDelegateMailSystem implements MailSystemInterface {

  /**
   * Implements MailSystemInterface::format().
   *
   * Retrieve the configured class responsible for formatting a message of a
   * given module and mail-key. Forwards the formatting to that class.
   */
  public function format(array $message) {
    $module = $message['module'];
    $key = $message['key'];
    $mailsystem = _mailsystem_delegate_get_mailsystem($module, $key, 'format');
    return $mailsystem->format($message);
  }

  /**
   * Implements MailSystemInterface::mail().
   *
   * Retrieve the configured class responsible for delivering a message of a
   * given module and mail-key. Forwards the call to that class.
   */
  public function mail(array $message) {
    $module = $message['module'];
    $key = $message['key'];
    $mailsystem = _mailsystem_delegate_get_mailsystem($module, $key, 'mail');
    return $mailsystem->mail($message);
  }

}

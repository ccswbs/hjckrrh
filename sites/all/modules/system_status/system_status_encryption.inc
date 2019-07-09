<?php
/**
 * @file
 * Encryption logic for system_status
 */

class SystemStatusEncryption {

  /**
   * System Status: create a new token.
   */
  public static function getToken() {
    $chars = array_merge(range(0, 9),
      range('a', 'z'),
      range('A', 'Z'),
      range(0, 99));

    shuffle($chars);

    $token = "";
    for ($i = 0; $i < 8; $i++) {
      $token .= $chars[$i];
    }

    return $token;
  }

  /**
   * System Status: encrypt a plaintext message using mcrypt.
   */
  public static function encrypt_mcrypt($plaintext) {
    $key = hash("SHA256", variable_get('system_status_encrypt_token', 'Error-no-token'), TRUE);

    $iv_size = mcrypt_get_iv_size(MCRYPT_RIJNDAEL_128, MCRYPT_MODE_CBC);
    $iv = mcrypt_create_iv($iv_size, MCRYPT_RAND);

    $plaintext_utf8 = utf8_encode($plaintext);

    $ciphertext = mcrypt_encrypt(MCRYPT_RIJNDAEL_128, $key, $plaintext_utf8, MCRYPT_MODE_CBC, $iv);

    $ciphertext = $iv . $ciphertext;

    return base64_encode($ciphertext);
  }


  /**
   * System Status: encrypt a plaintext message using openssl.
   */
  public static function encrypt_openssl($plaintext) {
    $key = hash("SHA256", variable_get('system_status_encrypt_token', 'Error-no-token'), TRUE);
    $plaintext_utf8 = utf8_encode($plaintext);

    $iv = openssl_random_pseudo_bytes(16);
    $cyphertext = openssl_encrypt($plaintext_utf8, 'AES-128-CBC', $key, OPENSSL_RAW_DATA, $iv);

    return base64_encode($iv.$cyphertext);
  }

}

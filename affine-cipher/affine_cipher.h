#ifndef AFFINE_CIPHER_H
#define AFFINE_CIPHER_H


extern const char *DEFAULT_KEY_FILENAME;

typedef struct {
  unsigned a;
  unsigned b;
} AffineCipher;

/* Write the cipher key to the provided `filename`. If the `filename`
 * is `NULL`, write to the default location `.key`. It will overwrite
 * any existing file!
 *
 * Returns 0 on success and 1 on failure.
 */
int affine_cipher_write_to_disk(AffineCipher *c, char *filename);

/* Read the cipher key from the provided `filename`, if the `filename`
 * is `NULL`, read from the default location `.key`.
 *
 * Returns 0 on success and 1 on failure.
 */
int affine_cipher_read_from_disk(AffineCipher *c, char *filename);


char affine_cipher_encrypt_char(AffineCipher *c, char plain_char);
char affine_cipher_decrypt_char(AffineCipher *c, char plain_char);

#endif /* AFFINE_CIPHER_H */

#ifndef V2PASSGEN_H
#define V2PASSGEN_H
#include <openssl/md5.h>

// Print the MD5 sum as hex-digits.
void print_md5_sum(unsigned char* md);
void generatePassword(const char* masterpassword, const char* resource, int round);
#endif // V2PASSGEN_H
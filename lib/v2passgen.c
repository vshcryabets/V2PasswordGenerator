#include "v2passgen.h"
#include <string.h>

// Print the MD5 sum as hex-digits.
void print_md5_sum(unsigned char* md) {
    int i;
    for(i=0; i <MD5_DIGEST_LENGTH; i++) {
        printf("%02x",md[i]);
    }
}

void generatePassword(const char* masterpassword, const char* resource, int round) {
    unsigned char * tmp_hash;
    tmp_hash = MD5(masterpassword, strlen(masterpassword), NULL);
    print_md5_sum(tmp_hash);
    return 0;
}

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
    char md5_hash[16];
    int masterLen = strlen(masterpassword);
    int resourceLen = strlen(resource);
    char buffer[masterLen+resourceLen+17];
    
    strncpy(buffer, masterpassword, masterLen);
    strncpy(buffer+masterLen, resource, resourceLen);

    do {
	MD5(buffer, strlen(buffer), md5_hash);
	strncpy(buffer, masterpassword, masterLen);
	strncpy(buffer+masterLen, resource, resourceLen);
	strncpy(buffer+masterLen+resourceLen, md5_hash, 16);
	//printf("Round %d\n", round);
    } while ( --round > 0 );

    print_md5_sum(md5_hash);

    return 0;
}

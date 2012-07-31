#include <openssl/md5.h>
#include <string.h>

// Print the MD5 sum as hex-digits.
void print_md5_sum(unsigned char* md) {
    int i;
    for(i=0; i <MD5_DIGEST_LENGTH; i++) {
        printf("%02x",md[i]);
    }
}

int main(void) {
    unsigned char * tmp_hash;
    const char *src = "12345";
    tmp_hash = MD5(src, strlen(src), NULL);
    print_md5_sum(tmp_hash);
    return 0;
}

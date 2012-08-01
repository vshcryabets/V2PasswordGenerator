#include "v2passgen.h"
#include "stdio.h"

int main(void) {
    char *masterPassword;
    char *resource;
    printf("Enter masterpassword: ");
    int res = scanf("%as", &masterPassword);
    masterPassword[res] = 0;
    printf("Enter resource name: ");
    res = scanf("%as", &resource);
    resource[res] = 0;
    printf("Mp=%s\n", masterPassword);
    generatePassword(masterPassword, resource, 1);
    //free(masterPassword);
    //free(resource);
    return 0;
}

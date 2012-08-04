#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include "v2passgen.h"

int main(void) {
	char *masterPassword = NULL;
	char *resource = NULL;
	
	printf("Enter master password: ");
	size_t bytes_read, nbytes = 0;
	bytes_read = getline(&masterPassword, &nbytes, stdin);
	if ( bytes_read < 1 ) {
		return 1;
	}
	masterPassword[bytes_read-1] = 0;
    
	printf("Enter resource name: ");
	bytes_read = getline(&resource, &nbytes, stdin);
	if ( bytes_read < 1 ) {
		return 1;
	}
	resource[bytes_read-1] = 0;

	generatePassword(masterPassword, resource, 10);
	free(masterPassword);
	free(resource);

	return 0;
}


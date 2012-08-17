#include "stdio.h"

const char *gTranslationTable="@!\"#$%&'()*+,-./0123456789:;<=>ABCDEFGHIJKLMNOPQRSTUVWXYZ[\]^abcdefghijklmnopqrstuvwxyz{|}~?_";

int divide(const unsigned char *input, unsigned char *output, int length, int *outlength) {
    int inpos = 0, outpos = 0;
    int counter = input[inpos];
    int divider = strlen(gTranslationTable);
    while ( 1 ) {
	if ( counter < divider ) {
	    inpos++;
	    if ( inpos >= length ) {
		break;
	    }
	    counter = counter*256 + (int)input[inpos];
	}
	int p = counter/divider;
	counter = counter - p*divider;
	output[outpos++] = (unsigned char)p;
    }
    (*outlength) = outpos;
    return counter;
}

char* convertToBase93(char* input, int inSize) {
    unsigned char* b = malloc(inSize);
    unsigned char* primary = input;
    unsigned char* secondary = b;
    unsigned char* res = malloc(inSize*3);
    int r = 0;
    int length = inSize;
    int outpos = 0;
    do {
	r = divide(primary, secondary, length, &length);
//	for ( int i = 0; i < length; i++ ) {
//	    printf("%p, ", secondary[i]);
//	}
	unsigned int *t = primary;
	primary = secondary;
	secondary = t;
//	printf("%c", gTranslationTable[r]);
	res[outpos++] = gTranslationTable[r];
    } while (length>0);
    res[outpos++] = 0;
    free(b);
    return res;
}

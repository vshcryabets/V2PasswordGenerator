#include "stdio.h"

int divide(const int *input, int *output, int length, int *outlength) {
    int inpos = 0, outpos = 0;
    int counter = input[inpos];
    int divider = 0x5D;
    int p = 0;
    while ( 1 ) {
	if ( counter < divider ) {
	    inpos++;
	    if ( inpos >= length ) {
		break;
	    }
	    counter = counter*256 + input[inpos];
	}
//        printf("C1=%p\n",counter);
	p = counter/divider;
	counter = counter - p*divider;
	output[outpos++] = p;
    }
    (*outlength) = outpos;
//    printf("\n");
    return counter;
}

int main() {
    int bs = 9;
    unsigned int a[] = {1,3,5,7,11, 0x6A,0x8A, 0xE5, 0x59};
    unsigned int b[] = {0,0,0,0,0,  0,0,0,0};
/*    unsigned int c = a[0]*256*256*256 + a[1]*256*256 + a[2]*256 + a[3];
    printf("Src %d=%p\n", c, c);
    while ( c > 0 ) {
	int p = c%93;
        c = c/93;
        printf(".%p",p);
    }
    printf("\n");*/
    unsigned int* primary = a;
    unsigned int* secondary = b;
    int r = 0;
    int length = bs;
    do {
	r = divide(primary, secondary, length, &length);
	for ( int i = 0; i < length; i++ ) {
	    printf("%p, ", secondary[i]);
	}
	unsigned int *t = primary;
	primary = secondary;
	secondary = t;
	printf("R=%p\n", r);
    } while (length>0);
}

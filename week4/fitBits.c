#include <stdio.h>

int fitsBits(int x, int n) {

    int shift = (~n + 1) + 32;

    int y = (x << shift) >> shift;

    return !(y ^ x);
}

int main() {

    printf( "%d\n", fitsBits(-4, 3) );
    return 0;
}
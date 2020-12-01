#include "tes.h"
#include <stdio.h>

int main() {
    NAMA x;
    // create(&x);
    x.A[0] = "tes";
    x.A[1] = "tes1";
    x.A[2] = "tes2";
    for (int i = 0; i < 10; i++) {
        printf("%s\n", x.A[i]);
    }
}
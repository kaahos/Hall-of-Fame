#include <stdio.h>
#include <stddef.h>

int main(void)
{
    int *x;
    printf("SIZEOF: %zu, %zu, %zu, %zu\n", sizeof(int), sizeof(*x), sizeof *x, (sizeof *x));
    // BTW the 1st one is the worst: if we change x type, we need to change all the sizeof...
    // But the 2 last are a litle more tricky: sizeof is not a function !!
    return 0;
}

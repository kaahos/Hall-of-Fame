#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // 16376
    size_t *t = malloc(sizeof(*t) * 32);
    size_t *m = malloc(sizeof(*m) * 32);
    printf("BEFORE %zu\n", t[-1]);
    // change malloc header to overlap 2 chunks
    t[-1] = 528 | 1;
    t[512] = 528;
    printf("AFTER %zu\n", t[-1]);
    free(t);
    free(m);
    char *s1 = malloc(sizeof(size_t) * 32);
    char *s2 = malloc(512);
    s1 = strcpy(s1, "hello world!");
    printf("s1: %s\n", s1);
    s2 = strcpy(s2, "Bwahahahaha I just want to break malloc ................."
        "koukou  ldwjkdjsbgxcnvbbjkhfhndvhbjdkhjfghvkjfnjkbhvjknklhfjhfbjkxbvjgfhgjkhjhgjhfbdkjbhjh"
        "koukou  ldwjkdjsbgxcnvbbjkhfhndvhbjdkhjfghvkjfnjkbhvjknklhfjhfbjkxbvjgfhgjkhjhgjhfbdkjbhjh"
        "koukou  1 2 3 4 5 6 7 8 9 0 11 12 1START overlap: YES I defeat malloc bwahahahahahahaha..."
        " koukou !!!!!!!");
    printf("s2: %s\n", s2);
    printf("s1: %s\n", s1);
    s1 = strcpy(s1, "hello world!");
    printf("s2: %s\n", s2);
    return 0;
}

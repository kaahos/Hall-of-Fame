#include <stdio.h>

/*
 * ISO C 1999: 6.5.17: Comma operator syntax:
 *
 * expression:
 *     assignment-expression
 *     expression , assignment-expression
 */

int main(void)
{
    return printf("hello world\n"), 0;
}

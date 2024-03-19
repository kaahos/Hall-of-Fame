// compile with: gcc -std=c99 -Werror -Wvla -Wall -Wextra -pedantic

int main(void)
{
    *(unsigned char *)0 = 0;
    return 0;
}

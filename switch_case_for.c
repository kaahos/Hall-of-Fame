#include <stdio.h>

int main(void)
{
    int i = 1;

    switch (i)
    {
    case 0:
        puts("toto");
        for (int i = 0; i < 10; i++)
        {
        case 1:
            puts("tata");
        }
        break;
    default:
        puts("titi");
        break;
    }
    return 0;
}

// Do some magic

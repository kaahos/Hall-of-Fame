#include <stdio.h>

// undefined by the standard

int main(void)
{
    unsigned char arr[300];
    char arr1[300];

    for (int i = 0; i < 300; i++)
    {
        arr[i] = i;
        arr1[i] = i;
        printf("%d %d ", arr[i], arr1[i]);
    }

    printf("%d\n", sizeof(unsigned char) == sizeof(char));

    return 0;
}

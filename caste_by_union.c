#include <stddef.h>
#include <stdio.h>

size_t ptr2size(void *ptr)
{
    // We can use that to interpret any value of type to any other type of same size
    // The value is read as an another type so the convertion between integer and float make the result unreadable...
    // However we can use the convertion between integer ant float to write floats in binary (for exemple)
    union {
        void *ptr;
        size_t res;
    } converter;
    converter.ptr = ptr;
    return converter.res;
}

int main(void)
{
    int x = 1000;
    void *ptr = &x;
    printf("ptr: %p\n", ptr);
    size_t converted = ptr2size(ptr);
    printf("size: %zu, 0x%zx\n", converted, converted);
    return 0;
}

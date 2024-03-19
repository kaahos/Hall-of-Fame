#include <stdint.h>
#include <stdio.h>

typedef struct Color {
    unsigned char r;
    unsigned char g;
    unsigned char b;
    unsigned char a;
} Color;

void ClearBackground(Color color)
{
    /* DO SOMETHING */
    printf("color: r: %d, g: %d, b: %d, a: %d\n", (uint8_t)color.r, (uint8_t)color.g, (uint8_t)color.b, (uint8_t)color.a);
}

int main(void)
{
    // We want to pass 0xFF181818 as a color in ClearBackground
    // Theoretically it's possible because the Color struct is a 4 bytes structure and our uint is also a 4 bytes value
    // By reinterpreting the following sequence of bit as the color struct, it will be possible to pass it in ClearBackground
    // To do so, an intuitive version is as follows:
    uint32_t color = 0xFF181818;
    ClearBackground(*(Color *)&color);
    // Explanations: we are taking our integer as a pointer, explicitly cast it to a Color pointer and then dereference it to pass a Color...

    // NOW THE TRICKY PART WILL BEGIN :)
    // We can consider to have an array of uint32_t with only one element which is our uint representing the color: uint32_t[1] { 0xFF181818 }
    // In that case, we can think of that array as a literal array: (uint32_t[1]) { 0xFF181818 }
    // By passing this entire thing to as an argument, it becomes a pointer
    // That's mean we can reinterpret it as a Color pointer and then dereference it
    ClearBackground(*(Color *)(uint32_t[1]){ 0xFF181818 }); // HAHAHAHAHA !!!!

    return 0;
}

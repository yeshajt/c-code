#include<stdio.h>
#include<string.h>
#include<cs50.h>

int main(void)
{
    // Whoa this is so cool!
    // 0123 returns 2 for strlen and 83 for example
    // 0123.0 returns 10 for strlen and 0.000000 for example
    // 0x123 returns 3 for strlen and 291 for example
    // 0.123 returns 8 for strlen and 0.000000 for example
    // User input makes sense
    float example = 0123.0;
    char buffer[5];
    sprintf(buffer, "%f", example);
    printf("%lu\n", strlen(buffer));
    printf("%f\n", example);
}
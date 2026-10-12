#include <stdio.h>

int main(void) {
    unsigned char c = 250;
    c = c + 10;
    printf("250 + 10 = %u\n", c);          // 预期：4

    int big = 2147483647;
    big = big + 1;
    printf("INT_MAX + 1 = %d\n", big);    // 你会看到负数（绕回了）

    float a = 0.1f + 0.2f; printf("%f", a);

    return 0;
}
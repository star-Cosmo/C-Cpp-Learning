#include <stdio.h>
int main()
{
    printf("%zu\n", sizeof(char));         // 1 字节
    printf("%zu\n", sizeof(short));        // 2 字节
    printf("%zu\n", sizeof(int));          // 4 字节
    printf("%zu\n", sizeof(long));         // Windows下4字节，Linux下8字节
    printf("%zu\n", sizeof(float));        // 4 字节
    printf("%zu\n", sizeof(double));       // 8 字节
    printf("%zu\n", sizeof(char) * 45);    // 45 字节（sizeof结果是size_t，用%zu）
    return 0;
}
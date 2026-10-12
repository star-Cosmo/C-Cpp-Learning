#include <stdio.h>

int main(void) {
    int a = 0;
    int b = 0;
    printf("请输入两个整数: ");
    scanf("%d %d", &a, &b);  // 从键盘读取两个整数输入并存储到变量a和b中
    printf("你输入的两个整数是: %d 和 %d\n", a, b);  // 输出读入的两个整数
    return 0;
}
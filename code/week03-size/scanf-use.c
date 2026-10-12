#include <stdio.h>

int main(void) {
    /* 一次读两个整数（留作对比，暂注释）：
    int a = 0, b = 0;
    printf("请输入两个整数: ");
    scanf("%d %d", &a, &b);   // 空格/回车隔开，一次读两个
    printf("你输入的两个整数是: %d 和 %d\n", a, b);
    */

    int a = 0;                 // 必须初始化：scanf 失败时不写 a，否则是垃圾值
    printf("请输入一个整数: ");
    scanf("%d", &a);           // &a = 取地址；scanf 把读到的值写进 a 的内存
    printf("你输入的整数是: %d\n", a);

    return 0;
}

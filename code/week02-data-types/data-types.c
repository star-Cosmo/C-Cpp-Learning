#include <stdio.h>   // 包含标准输入输出库，提供printf等函数
/* std==standard标准
i==input输入
o==output输出 */
int main(){
    // printf("100\n");      // 直接输出字符串"100"
    // printf("%d\n",100);    // 使用%d格式化输出整数100
    // printf("%f\n",100.0);  // 使用%f格式化输出浮点数100.0
    printf("%c\n",'a');    // 使用%c格式化输出字符'a'
    int a=15;                 // 定义整数变量a并初始化为15
    scanf("%d",&a);        // 从键盘读取整数输入并存储到变量a中（%d=整数格式，&a=取变量a的地址）
    printf("%d\n",a);      // 输出读入的整数
}
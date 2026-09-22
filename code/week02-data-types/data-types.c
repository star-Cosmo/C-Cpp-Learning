#include <stdio.h>   // 包含标准输入输出库，提供printf等函数
#include <stdlib.h>  // 提供system函数
/* std==standard标准
i==input输入
o==output输出 */
int main(){
    system("chcp 65001");  // 设置终端编码为UTF-8，解决中文乱码

    //%d:整数格式化输出
    //%f:浮点数格式化输出
    //%c:字符格式化输出
    //%s:字符串格式化输出
    //%p:指针格式化输出
    //%u:无符号整数格式化输出
    

    // printf("100\n");      // 直接输出字符串"100"
    char a = 'A';              // 定义字符变量a并初始化为'A'
    printf("%c\n",a);    // 使用%c格式化输出字符'A'
    printf("%d\n",a);    // 使用%d格式化输出字符'A'对应的ASCII码值（65）
    // printf("%f\n",100.0);  // 使用%f格式化输出浮点数100.0
    // printf("%c\n",'a');    // 使用%c格式化输出字符'a'
    // int a=15;                 // 定义整数变量a并初始化为15
    // scanf("%d",&a);        // 从键盘读取整数输入并存储到变量a中（%d=整数格式，&a=取变量a的地址）
    // printf("%d\n",a);      // 输出读入的整数

/*     int i =0;              // 定义循环变量i并初始化为0
    for(i=32;i<=107;i++){  // for循环：从i=32开始，到i=107结束，每次i增加1
        printf("%c ",i);   // 将整数i作为ASCII码，输出对应的字符（%c=字符格式）
    }
     */
    char arr1[] = "abc";
    char arr2[] = {'a','b','c'};

    printf("%s\n", arr1);
    printf("%s\n", arr2);

    printf("are  u ok ?？？");
    printf("C\\Users");
    return 0;              // 返回0，表示程序正常结束
}
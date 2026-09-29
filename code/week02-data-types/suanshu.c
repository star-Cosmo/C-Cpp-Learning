#include <stdio.h> // 引入标准输入输出库

int main(){
/*     int a = 10; // 定义整数变量a并初始化为10
    int b = 20; // 定义整数变量b并初始化为20
    int c = 30; // 定义整数变量c并将a和b的和赋值给c
    printf("a + b = %d\n", a+b); // 输出a和b的和
    // c=b+3=a-1; // 这行代码有语法错误，无法编译
    a=a+3; // 将a的值增加3
    printf("a = %d\n", a); // 输出a的值
    a+=3; // 将a的值增加3，等价于a = a + 3
    printf("a = %d\n", a); // 输出a的值

    c+=5; // 将c的值增加5，等价于c = c + 5
    printf("c = %d\n", c); // 输出c的值

    a++; // 将a的值增加1，等价于a = a + 1
    printf("a = %d\n", a); // 输出a的值
    b--; // 将b的值减少1，等价于b = b - 1
    printf("b = %d\n", b); // 输出b的值
    int d = ++a; // 定义整数变量d并将a的值增加1后赋值给d
    printf("d = %d\n", d); // 输出d的值
    int e = --b; // 定义整数变量e并将b的值减少1后赋值给e
    printf("e = %d\n", e); // 输出e的值
 */
    int a = 10; // 定义整数变量a并初始化为10
    int b=++a; // 定义整数变量b并将a的值增加1后赋值给b
    // int c=a++; // 定义整数变量c并将a的值赋值给c后再将a的值增加1
    printf("a = %d\n", a); // 输出a的值12
    printf("b = %d\n", b); // 输出b的值11
    // printf("c = %d\n", c); // 输出c的值11 

    return 0; // 返回0，表示程序正常结束

}
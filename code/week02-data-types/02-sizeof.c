#include <stdio.h>   // printf
#include <stdlib.h>  // system（chcp 切换终端编码）
#include <limits.h>  // 提供 INT_MAX、CHAR_MAX 等取值范围宏

/* ============================================================
 * 第 2 周 第 2 天：sizeof + 数据类型大小 + 有符号/无符号
 * 对应视频：鹏哥 P16 数据类型的长度和sizeof操作符
 *           鹏哥 P17 signed 和 unsigned
 *           鹏哥 P18 数据类型的取值范围
 * 练习编号：02 类型大小查询器
 *
 * 核心概念：
 * 1. sizeof 是"操作符"（不是函数），用来问"这个类型/变量占几个字节"
 * 2. 1 字节(byte) = 8 位(bit)，能表示 0~255 共 256 个数
 * 3. signed（有符号）能存负数；unsigned（无符号）只能存非负数
 * 4. 同样 4 字节：signed int 范围约 -21亿 ~ +21亿
 *                unsigned int 范围约 0 ~ 42亿
 * ============================================================ */

int main(void) {
    system("chcp 65001");   // 终端切 UTF-8，防中文乱码

    /* ---------- 一、sizeof：问类型占几个字节 ---------- */
    // sizeof 返回的是 size_t（无符号整数），用 %zu 打印最安全
    printf("===== 各类型占用的字节数 =====\n");
    printf("char       : %zu 字节\n", sizeof(char));         // 1 字节
    printf("short      : %zu 字节\n", sizeof(short));        // 2 字节
    printf("int        : %zu 字节\n", sizeof(int));          // 4 字节
    printf("long       : %zu 字节\n", sizeof(long));         // 4 或 8（看平台）
    printf("long long  : %zu 字节\n", sizeof(long long));    // 8 字节
    printf("float      : %zu 字节\n", sizeof(float));        // 4 字节
    printf("double     : %zu 字节\n", sizeof(double));       // 8 字节

    // sizeof 也可以问变量：问的是"这个变量的类型占多大"，跟变量当前值无关
    int a = 100;
    printf("sizeof(a)  : %zu 字节（a 是 int）\n", sizeof(a));

    // 换算关系：字节 → 位
    printf("\n1 字节 = 8 位，所以 int 的 4 字节 = %zu 位\n", sizeof(int) * 8);

    /* ---------- 二、取值范围：从字节数推导 ---------- */
    // n 位能表示 2^n 个数
    // signed 一半是负数一半是非负数 → 范围是 -2^(n-1) ~ 2^(n-1)-1
    // unsigned 全是非负数          → 范围是 0 ~ 2^n - 1
    printf("\n===== 取值范围 =====\n");
    printf("char  (8位)  : signed   %d ~ %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("char  (8位)  : unsigned 0 ~ %u\n", UCHAR_MAX);
    printf("int  (32位)  : signed   %d ~ %d\n", INT_MIN, INT_MAX);
    printf("int  (32位)  : unsigned 0 ~ %u\n", UINT_MAX);

    /* ---------- 三、signed vs unsigned 实验 ---------- */
    printf("\n===== signed vs unsigned =====\n");

    // 同样 4 字节的内存，两种"读法"
    unsigned int u = 4294967295u;   // unsigned int 最大值（2^32 - 1）
    signed   int s = -1;            // signed int 最小值附近的负数

    printf("unsigned int 最大值 : %u\n", u);
    printf("signed int    -1    : %d\n", s);

    // 关键实验：同一块内存（全是二进制 1），两种解读
    // -1 的补码 = 32 个 1，unsigned 读它 = 4294967295
    unsigned int reinterpret = (unsigned int)s;
    printf("-1 用 unsigned 读出来 : %u  （看到了吗？同一块内存两种解释）\n", reinterpret);

    // 判断技巧：写代码时 unsigned 加 u 后缀，提醒自己是无符号
    unsigned int positive_only = 100u;
    printf("positive_only = %u\n", positive_only);

    /* ---------- 四、嵌入式预告（为什么 signed/unsigned 很重要） ---------- */
    // MCU 里寄存器全是 unsigned！比如：
    //   uint8_t  = unsigned char   （8位，0~255，对应 8 位寄存器）
    //   uint16_t = unsigned short  （16位，0~65535）
    //   uint32_t = unsigned int    （32位）
    // 写错符号 → 判断条件出诡异 bug，是嵌入式面试必考题！
    printf("\n===== 嵌入式常用类型预告 =====\n");
    printf("uint8_t  实际就是 unsigned char  : %zu 字节\n", sizeof(unsigned char));
    printf("uint16_t 实际就是 unsigned short : %zu 字节\n", sizeof(unsigned short));
    printf("uint32_t 实际就是 unsigned int   : %zu 字节\n", sizeof(unsigned int));

    /* ---------- 五、动手小练习（做完删掉注释运行） ---------- */
    // 练习 1：打印 long double 占几个字节
    // printf("long double: %zu 字节\n", sizeof(long double));

    // 练习 2：自己算一下 short（16位）signed 的最大值是多少？
    //         提示：2^15 - 1 = 32767
    // printf("short signed max = %d\n", SHRT_MAX);

    // 练习 3：unsigned char 加到 255 再 +1 会怎样？（下节课溢出实验预告）
    // unsigned char c = 255;
    // c = c + 1;
    // printf("255 + 1 = %u\n", c);   // 猜猜输出什么？

    printf("\n===== 完成！去 README 打勾，提交 git =====\n");
    return 0;
}

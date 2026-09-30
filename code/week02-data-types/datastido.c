#include <stdio.h>   // 标准输入输出库：printf 和 scanf 的声明都在这个头文件里
int main(){
    // 原则：先打印提示、再等待输入，用户才知道该输什么
    // \n 让提示先显示再等待输入（简单讲: 行缓冲 line buffering 「英文术语: line buffer（行缓冲）」——输出攒够一行才真正显示出来）
    printf("scanf one num\n");

    int num;   // 在栈上分配一个 int 变量的空间「英文术语: stack（栈）」
    // & 是取地址操作符「英文术语: address-of operator（取地址操作符）」：取出 num 在栈上的内存地址
    // scanf 拿到变量的栈地址，才能把键盘输入直接写进那块内存
    // printf 只读取值的副本，所以不用 &
    // 忘记写 & → 传入垃圾地址 → 崩溃/未定义行为「英文术语: undefined behavior（未定义行为）」
    scanf("%d", &num);

    printf("You entered: %d\n", num);   // printf 只读变量的值，不需要 &
    printf("scanf two nums\n");   // 同样：先提示，再输入

    int num1, num2;   // 一次声明两个 int 变量
    // 格式串里的空格能匹配输入里的任意空白（空格/回车/Tab），所以两个数字怎么隔开输入都行
    // 每个变量前都要写 &，一个都不能漏
    scanf("%d %d", &num1, &num2);

    printf("You entered: %d and %d\n", num1, num2);   // %d 按顺序依次对应后面的变量

    // 后置自增「英文术语: post-increment（后置自增）」：先把 num1 的旧值赋给 num3，num1 自己再加 1（先用后加）
    int num3 = num1++;

    printf("num1 = %d\n", num1);   // 此时 num1 已经加过 1
    printf("num3 = %d\n", num3);   // num3 拿到的是加 1 之前的旧值

    // 前置自增「英文术语: pre-increment（前置自增）」：num1 先加 1，再把新值赋给 num4（先加后用）
    // 底层：编译器通常把两种 ++ 都编译成同一条 INC 指令「英文术语: INC instruction（自增指令）」，差别只在"表达式取旧值还是新值"
    int num4 = ++num1;
    printf("num1 = %d\n", num1);   // num1 又加了 1
    printf("num4 = %d\n", num4);   // num4 拿到的是加 1 之后的新值

    return 0;   // 返回 0 告诉操作系统：程序正常结束
}

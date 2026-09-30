#include <stdio.h>
int main()
{
    // sizeof 是操作符不是函数「英文术语: operator（操作符）」：编译期求值
    // 「英文术语: compile-time evaluation（编译期求值）/ constant expression（常量表达式）」，
    // 运行时零开销、不产生机器码。单位是字节：1 字节 = 8 位「英文术语: bit（位）/ byte（字节）」
    // sizeof(char) 恒等于 1，这是 C 标准强制规定，不是巧合
    printf("%zu\n", sizeof(char));         // 1 字节（char=1，标准保证）
    printf("%zu\n", sizeof(short));        // 2 字节（short=2）
    printf("%zu\n", sizeof(int));          // 4 字节（int=4）
    // 各类型大小由平台 ABI 决定「英文术语: ABI, Application Binary Interface（应用二进制接口）」：
    // Windows x64 是 LLP64 → int=4, long=4, long long=8；Linux x64 是 LP64 → long=8
    printf("%zu\n", sizeof(long));         // Windows下4字节，Linux下8字节（long=4 于 Win）
    printf("%zu\n", sizeof(float));        // 4 字节（float=4）
    printf("%zu\n", sizeof(double));       // 8 字节（double=8）
    // sizeof(char)*45：常量折叠「英文术语: constant folding（常量折叠）」——编译期直接算出 45，程序里只剩结果
    // %zu 讲解：z = size_t 长度修饰符，u = 无符号；size_t 是表示对象大小的无符号整数类型「英文术语: size_t」
    // 之前用 %d 会出警告，因为 %d 对应 int，而 sizeof 的结果是 size_t，类型不匹配
    printf("%zu\n", sizeof(char) * 45);    // 45 字节（sizeof结果是size_t，用%zu）
    return 0;   // 返回 0，表示程序正常结束
}
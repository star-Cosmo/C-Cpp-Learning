#include <stdio.h>
#include <windows.h>  // 用于设置控制台编码，解决中文乱码
#include <locale.h>   // 用于设置本地化环境，支持宽字符中文

int main(void) {
    SetConsoleOutputCP(65001);  // 设置控制台为UTF-8编码
    setlocale(LC_ALL, "");      // 设置本地化环境，支持中文宽字符

    /* ===== 版本1：原始的单个字符输入（char类型，只能存英文） ===== */
    /*
    char c;
    printf("请输入一个字符: ");
    scanf("%c", &c);
    printf("你输入的字符是: %c\n", c);
    // 问题：输入中文会显示乱码或?，因为char只有1字节
    */

    /* ===== 版本2：单个宽字符输入（wchar_t类型，可以存中文） ===== */
    /*
    wchar_t wc;  // 宽字符类型，可以存储中文
    wprintf(L"请输入一个字符: ");
    wscanf(L"%lc", &wc);  // %lc 用于读取宽字符
    wprintf(L"你输入的字符是: %lc\n", wc);
    // 改进：使用wchar_t可以存储中文等宽字符
    */

    /* ===== 版本3：字符串输入（宽字符数组，可存多个中英文混合）【当前使用】 ===== */
 /*    wchar_t str[100];  // 宽字符数组，可以存储最多99个字符+结束符
    wprintf(L"请输入一串字符（中英文、数字、符号都可以）: ");
    wscanf(L"%99ls", str);  // %ls 用于读取宽字符串，99限制长度防止溢出
    wprintf(L"你输入的是: %ls\n", str); */
    // 改进：使用数组可以存储一串字符，支持中英文、数字、符号混合输入


    int a;
    int b;
    printf("请输入两个整数: ");
    scanf("%d,%d", &a, &b);  // 使用%d读取整数，用逗号分隔输入
    printf("你输入的两个整数是: %d 和 %d\n", a, b);


    /* ===== 方法2：fgets() - 最安全的字符串输入【推荐】 ===== */
    /*
    char str[100];
    printf("\n[方法2: fgets] 请输入一串字符: ");
    fgets(str, sizeof(str), stdin);  // 从标准输入读取，自动限制长度，安全！
    // 注意：fgets会读取换行符，需要手动去除
    str[strcspn(str, "\n")] = '\0';  // 去除末尾的换行符
    printf("你输入的是: %s\n", str);
    // 优点：安全、自动限制长度、不会缓冲区溢出
    // 缺点：会读入换行符
    */

    /* ===== 方法3：getchar() - 逐个字符读取 ===== */
    /*
    char ch;
    printf("\n[方法3: getchar] 请输入一个字符: ");
    ch = getchar();  // 读取单个字符，不需要&
    printf("你输入的字符是: %c\n", ch);
    // 特点：简单直接，但一次只能读一个字符
    // 常用于：暂停程序（按任意键继续）、菜单选择等
    */

    /* ===== 方法4：gets_s() - C11标准的安全输入 ===== */
    /*
    char str2[100];
    printf("\n[方法4: gets_s] 请输入一串字符: ");
    gets_s(str2, 100);  // C11标准，比gets安全，指定最大长度
    printf("你输入的是: %s\n", str2);
    // 注意：仅C11及以后标准支持，部分编译器可能不支持
    */

    /* ===== 方法5：getch() - Windows特有，无需回车确认 ===== */
    /*
    #include <conio.h>  // 需要额外包含这个头文件
    char key;
    printf("\n[方法5: getch] 按任意键（无需回车）: ");
    key = getch();  // 立即返回，不需要按回车，也不显示字符
    printf("\n你按下的键是: %c (ASCII码: %d)\n", key, key);
    // 特点：无需回车、可捕获方向键等特殊按键、常用于游戏开发
    // 缺点：仅Windows支持，不可移植
    */


    /* ===== 【重点】格式说明符完全指南 ===== */
    /*
    printf("========== 格式说明符（Format Specifier）详解 ==========\n");

    // 1. %d 或 %i - 整数（十进制）
    int age = 25;
    printf("[%%d] 我的年龄是: %d 岁\n", age);

    // 2. %f - 浮点数（小数）
    float height = 175.5f;
    printf("[%%f] 我的身高是: %f 厘米\n", height);        // 默认6位小数
    printf("[%%.2f] 我的身高是: %.2f 厘米\n", height);   // 保留2位小数

    // 3. %c - 单个字符
    char grade = 'A';
    printf("[%%c] 我的等级是: %c\n", grade);

    // 4. %s - 字符串
    char name[] = "张三";
    printf("[%%s] 我的名字是: %s\n", name);

    // 5. %x 或 %X - 十六进制整数
    int color = 255;
    printf("[%%x] 颜色值(小写): %x\n", color);     // 输出: ff
    printf("[%%X] 颜色值(大写): %X\n", color);     // 输出: FF

    // 6. %o - 八进制整数
    int num = 64;
    printf("[%%o] 八进制表示: %o\n", num);          // 输出: 100

    // 7. %e 或 %E - 科学计数法
    double pi = 3.14159265358979;
    printf("[%%e] 科学计数法: %e\n", pi);          // 输出: 3.141593e+00

    // 8. %% - 输出百分号本身
    double progress = 99.9;
    printf("[%%] 完成度: %.1f%%\n", progress);     // 输出: 99.9%

    // 9. %p - 指针地址（内存地址）
    int value = 42;
    printf("[%%p] 变量value的地址: %p\n", (void*)&value);

    // 10. %ld - 长整数（long）
    long bigNumber = 1234567890L;
    printf("[%%ld] 大数字: %ld\n", bigNumber);

    // 11. %llu - 超长整数（unsigned long long）
    unsigned long long hugeNumber = 999999999999ULL;
    printf("[%%llu] 超大数字: %llu\n", hugeNumber);
    */


    return 0;
}
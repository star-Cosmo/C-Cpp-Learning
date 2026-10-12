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
    wchar_t str[100];  // 宽字符数组，可以存储最多99个字符+结束符
    wprintf(L"请输入一串字符（中英文、数字、符号都可以）: ");
    wscanf(L"%99ls", str);  // %ls 用于读取宽字符串，99限制长度防止溢出
    wprintf(L"你输入的是: %ls\n", str);
    // 改进：使用数组可以存储一串字符，支持中英文、数字、符号混合输入

    return 0;
}
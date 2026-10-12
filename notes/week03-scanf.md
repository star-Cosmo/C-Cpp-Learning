# 第 3 周笔记：scanf

## 基本用法

- `scanf("%d", &a)` —— 读一个整数，`&` 是取地址（scanf 要往变量的内存里写，所以传地址）
- `scanf("%d %d", &a, &b)` —— 一次读多个，空格/回车隔开
- 返回值 = 成功读到的个数（成功 1 个返回 1，失败返回 0）

## scanf 的 3 个坑（整数）

1. **溢出**：数超过 int 范围（±21 亿），scanf 不报错、静默溢出 → 34 位数字得到 -1
2. **未初始化**：`int a;` 忘了 `= 0`，scanf 失败时 a 是垃圾值
3. **非数字输入**：scanf 失败（返回 0）且不写变量，坏数据留在缓冲区

## 读中文：char 存不下，要用宽字符 wchar_t

`char` 只有 1 字节，存不下中文（UTF-8 一个汉字 3 字节）→ 用 **宽字符 `wchar_t`**。

**试错路径**（`scanf-use.c` 三个版本）：

1. `char c` —— 1 字节，读中文乱码 / 变 `?` ❌
2. `wchar_t wc` —— 单个宽字符，能存一个中文 ✅
3. `wchar_t str[100]` —— 宽字符串，能存一串中英文混合 ✅（当前用）

```c
#include <locale.h>
#include <windows.h>

setlocale(LC_ALL, "");        // 让程序支持宽字符读写（必须）
SetConsoleOutputCP(65001);    // 让控制台按 UTF-8 显示中文（Windows 专有）

wchar_t str[100];
wprintf(L"请输入: ");          // wprintf / wscanf = 宽字符版 printf / scanf
wscanf(L"%99ls", str);        // %lc 单个宽字符 / %ls 宽字符串；99 防溢出
wprintf(L"你输入的是: %ls\n", str);
```

**记法**：

| 写法 | 含义 |
|---|---|
| `L"..."` | 宽字符串字面量 |
| `wchar_t` | 宽字符类型（Windows 下 2 字节） |
| `wprintf` / `wscanf` | printf / scanf 的宽字符版 |
| `%lc` / `%ls` | 单个宽字符 / 宽字符串 |
| `%99ls` | 最多读 99 个字符（数组 100，留 1 位给 `\0`，防溢出） |

> 💡 两行设置缺一不可：`setlocale` 管"程序认不认宽字符"，`SetConsoleOutputCP` 管"控制台怎么显示"。

## 配套实验

- `scanf-use.c` —— 读中文三版试错：char → wchar_t → 宽字符串
- `test01.c` —— 整数溢出（250+10=4、INT_MAX+1 绕回）+ 浮点精度（0.1f+0.2f≠0.3）

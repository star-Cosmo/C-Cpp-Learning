# 第 1 周：环境搭建与第一个程序

## 今日学习内容
- 环境搭建：MSYS2 + GCC 16.2.0 + GDB 17.2
- VSCode 配置：.vscode/ 下的 c_cpp_properties.json、launch.json、tasks.json
- 第一个 C 程序：Hello World
- 中文路径会导致编译失败，目录/文件名必须英文

## 重要代码
```c
#include <stdio.h>

int main() {
    printf("Hello World!\n");
    return 0;
}
```

## 踩坑记录
- 中文路径：ld.exe 无法处理中文路径，报 cannot open output file
- VSCode 便携版路径：E:\Visual Studio Code\VSCode\Microsoft VS Code\Code.exe
- MSYS2 安装位置：E:\Workstation\Tools\msys64
- MSYS2 的 gcc 子进程 cc1.exe 依赖 ucrt64\bin 里的 DLL，VSCode 需完全重启才拿到新 PATH

## 明日计划
- 开始第 2 周：数据类型
- 看鹏哥 C 语言 P1-P14「C语言常见概念」

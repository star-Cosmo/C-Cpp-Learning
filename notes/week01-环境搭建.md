# 第 1 周笔记：环境搭建 + 第一个程序

- 环境：MSYS2（GCC 16.2.0 + GDB 17.2）+ VSCode
- 第一个程序：

```c
#include <stdio.h>
int main() { printf("Hello World!\n"); return 0; }
```

- 关键路径：MSYS2 = `E:\Workstation\Tools\msys64`

## 踩坑

- **中文路径**：ld.exe 报 `cannot open output file` → 目录/文件名必须英文
- **装完工具**：gcc 的 cc1.exe 依赖 `ucrt64\bin` 的 DLL → VSCode 要**完全重启**才认新 PATH

# code — 练习代码

按**周**建立文件夹，存放每天的练习代码。

```
code/
├── week01-hello-world/       # 第1周：环境 + Hello World
├── week02-data-types/        # 第2周：数据类型
├── week03-operators/         # 第3周：运算符
├── week04-if-switch/         # 第4周：分支
├── week05-loops/             # 第5周：循环
├── week06-functions/         # 第6周：函数
├── week07-arrays/            # 第7周：数组
├── week08-strings/           # 第8周：字符串
├── week09-pointers/          # 第9-10周：指针
├── week10-struct-union/      # 第11周：结构体
├── week11-memory/            # 第12周：内存管理
└── week12-bit-operations/    # 第13周：位运算
```

> ⚠️ **重要：文件夹和文件名必须用英文或拼音，不能用中文。**
> MSYS2 的 gcc 在 Windows 上处理中文路径会报错（`ld.exe: cannot open output file`）。
> 这是实测踩过的坑（`ch01-环境与第一个程序/` 编译失败）。

## 命名规范

文件用英文或拼音命名，例如：

```
week02-sum-two-numbers.c
week05-nine-nine-table.c
```

## 编译运行

```bash
# 编译
gcc helloworld.c -o test

# 运行（Windows）
./test.exe
```

> 💡 每写完一个程序，**立刻编译运行验证**，不要攒着。

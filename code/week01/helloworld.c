// #include 是预处理指令（英文术语: preprocessor 预处理器）
// 原理：编译的第一步，预处理器把 stdio.h 头文件的内容【原样粘贴】到这里，
//       编译器才能认识 printf 这个函数长什么样
// 一个 .c 变成 .exe 要经过四步流水线（英文术语: 四步）：
//   预处理(preprocess) → 编译(compile) → 汇编(assemble) → 链接(link)
#include <stdio.h>

// main 函数是程序的入口（英文术语: entry point 入口点）
// 原理：双击 .exe 后，操作系统（英文术语: OS）加载程序，从 main 第一行开始执行
// void = 不要外界给参数；int = 结束时返回一个整数给操作系统
int main(void) {
	// printf：把文字打印到屏幕（stdio = standard input/output 标准输入输出，f = format 格式化）
	// "hello world\n" 是字符串常量（英文术语: string literal），
	// 编译后被放在只读数据段（英文术语: .rodata = read-only data 只读数据区），
	// 程序运行时只准读、不准改
	// \n 是转义字符，表示"换行"
	printf("hello world\n");
	// return 0：把 0 作为退出码交还给操作系统（英文术语: exit code 退出码）
	// 行业约定：0 = 程序正常结束，非 0 = 出错了 —— 脚本/系统靠它判断成败
	return 0;
}

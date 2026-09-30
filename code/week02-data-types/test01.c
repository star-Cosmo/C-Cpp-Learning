#include <stdio.h>
#include <stdlib.h>

int main() {
    system("chcp 65001");  // 设置UTF-8

    printf("第一行\n第二行\n");      // \n 换行
    printf("姓名\t年龄\t城市\n");     // \t 制表符对齐
    printf("张三\t20\t北京\n");
    printf("李四\t25\t上海\n");

    printf("路径：C:\\Users\\test\n");  // \\ 打印一个反斜杠
    printf("他说：\"你好\"\n");         // \" 打印双引符
    printf("字符：\'A\'\n");           // \' 打印单引号

    return 0;
}
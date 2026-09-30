#include <stdio.h>
#include <stdlib.h>

/* ============================================================
 * 输入输出考题程序（第 2 周 · 选集 25-28 配套）
 *
 * 用法：运行 → 依次答 5 道题 → 全部答完后自动把答案
 *       保存到同目录的 io-quiz-answers.txt 文件里
 *
 * 考点：printf/scanf、ASCII、sizeof、转义字符（全是已学内容）
 *
 * ⚠️ 超前知识：本程序用了文件操作（fopen/fprintf/fclose），
 *    这是选集 172+ 的内容，现在只要会套用即可，注释已标原理
 * ============================================================ */

int main(void) {
    system("chcp 65001");   // 切控制台代码页为 UTF-8（英文术语: codepage），防中文乱码

    /* ---- 答案变量：每个题一个 int，答完统一写进文件 ---- */
    int a1, a2, a3, a4, a5;

    printf("========== 输入输出考题（共5题）==========\n");
    printf("提示：选择题输入序号，填空题输入数字，回车提交\n\n");

    /* 第 1 题：格式符（考点：printf 的 format string） */
    printf("Q1. 想打印一个整数，应该用哪个格式符？\n");
    printf("    1) %%d   2) %%f   3) %%c   4) %%s\n");
    printf("你的答案: ");
    scanf("%d", &a1);          // & 取地址：scanf 要把输入写进 a1 的栈内存（英文术语: stack 栈）

    /* 第 2 题：ASCII（考点：字符的本质是整数） */
    printf("\nQ2. 字符 'A' 的 ASCII 码值是多少？（输入数字）\n");
    printf("你的答案: ");
    scanf("%d", &a2);

    /* 第 3 题：sizeof（考点：类型占几字节） */
    printf("\nQ3. 在你的电脑上 sizeof(int) 是几字节？\n");
    printf("你的答案: ");
    scanf("%d", &a3);

    /* 第 4 题：字符串与 \0（考点：字符串占内存含终止符） */
    printf("\nQ4. 字符串 \"abc\" 在内存里占几个字节？（含 '\\0'）\n");
    printf("你的答案: ");
    scanf("%d", &a4);

    /* 第 5 题：转义字符（考点：\\n 的字节值） */
    printf("\nQ5. 转义字符 \\n 对应的 ASCII 值是多少？\n");
    printf("你的答案: ");
    scanf("%d", &a5);

    /* ================= 答案保存到文件 =================
     * 文件操作三步曲（选集 172 会细讲，先当模板记住）：
     *   fopen  → 打开/创建文件，返回文件指针（英文术语: file pointer）
     *           "w" = write 写模式（英文术语: write mode），文件不存在就创建
     *   fprintf→ 往文件里"打印"，用法和 printf 几乎一样，
     *           只是 printf 打到屏幕，fprintf 打到文件
     *   fclose → 关闭文件，把缓冲区剩余数据真正写入磁盘
     * =================================================== */
    FILE *fp = fopen("io-quiz-answers.txt", "w");   // 在程序所在目录创建答案文件

    if (fp == NULL) {           // 判空是文件操作的铁律：打不开（没权限/磁盘满）必须先报告
        printf("\n错误：答案文件创建失败！\n");
        return 1;               // 返回非 0 给操作系统 = 程序出错（英文术语: exit code）
    }

    fprintf(fp, "===== 输入输出考题 答案记录 =====\n");
    fprintf(fp, "Q1. 格式符选择     你的答案: %d   正确: 1 (%%d)\n", a1);
    fprintf(fp, "Q2. 'A'的ASCII码   你的答案: %d   正确: 65\n",      a2);
    fprintf(fp, "Q3. sizeof(int)    你的答案: %d   正确: 4\n",        a3);
    fprintf(fp, "Q4. \"abc\"占几字节  你的答案: %d   正确: 4\n",        a4);
    fprintf(fp, "Q5. \\n的ASCII值    你的答案: %d   正确: 10\n",        a5);

    fclose(fp);                 // 忘记 fclose → 数据可能还留在缓冲区没写进磁盘

    printf("\n========== 答题结束 ==========\n");
    printf("你的答案已保存到: io-quiz-answers.txt\n");
    printf("（文件里附了正确答案，自己对一下）\n");

    return 0;   // 0 = 正常结束
}

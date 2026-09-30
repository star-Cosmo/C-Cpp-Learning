#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

/* ============================================================
 * 输入输出考题程序（第 2 周 · 选集 25-28 配套）
 *
 * 用法：运行 → 依次答 6 道题 → 全部答完后自动把答案
 *       保存到同目录的 io-quiz-answers.txt 文件里
 *
 * 考点：printf/scanf、ASCII、sizeof、转义字符、fgets 中文输入
 *       + 输入校验（英文术语: input validation，防御式编程 defensive programming）
 *
 * 输入规则（2026-09-30 加强，覆盖控制台里能敲出的任何东西）：
 *   · 客观题 Q1~Q5：非法输入（非数字 / 空回车 / 带字母 / 超范围 / 超长）
 *                   → 提示 1 次 → 给 1 次重输机会 → 仍非法则本题记 0 分继续
 *     （Q1 是选择题，只认 1~4；Q2~Q5 任意整数都收，答错没关系，文件里对答案）
 *   · 主观题 Q6：永不拒绝，任何内容（含空行）原样保留，
 *     存进 txt 后交由人工审查
 *   · EOF（Ctrl+Z 回车 / 管道断开）：优雅收尾，不卡死不崩溃
 *
 * ⚠️ 超前知识（现在只要会套用，注释已标原理）：
 *   1. 文件操作 fopen/fprintf/fclose 是选集 172+ 的内容
 *   2. 自定义函数（下面 read_line / parse_int / ask_int）是选集 90+ 的内容
 * ============================================================ */

/* ------------------------------------------------------------
 * read_line —— 安全读一整行
 *
 * 为什么不用 scanf("%s")？%s 遇空白就停、不查长度会把内存写爆、
 * 还挑食。fgets 读到换行为止，永远不写越界
 * （最多 cap-1 字节 + 自动补结束符 '\0'）。
 *
 * 返回值（英文术语: return value）：
 *    1 = 正常读到一整行
 *    0 = 输入结束 EOF（Ctrl+Z 回车，或管道/文件被关闭）
 *   -1 = 这一行太长被截断（本行剩余字符已手动排掉，不污染下一题）
 * ------------------------------------------------------------ */
static int read_line(char *buf, int cap) {
    if (fgets(buf, cap, stdin) == NULL) {
        return 0;   /* fgets 返回 NULL = 再也没有输入了 */
    }

    /* 找不到 '\n' → 输入超长被截断（fgets 装不下整行） */
    if (strchr(buf, '\n') == NULL) {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF) {
            ;   /* 把本行剩余字符全部排掉（英文术语: drain 排空），
                 * 否则残渣会被下一题当成答案读走 */
        }
        return -1;
    }

    /* 去掉行尾换行：管道输入可能是 "\r\n"，两个都要抹掉 */
    int len = 0;
    while (buf[len] != '\0') len++;         /* 手动数长度（strlen 的底层原理） */
    if (len > 0 && buf[len - 1] == '\n') { buf[--len] = '\0'; }
    if (len > 0 && buf[len - 1] == '\r') { buf[--len] = '\0'; }
    return 1;
}

/* ------------------------------------------------------------
 * parse_int —— 严格解析整数（英文术语: parse 解析）
 *
 * 能挡掉的坏输入：空行、"不知道"、"65abc"、"1.5"（点号）、
 *                 "+-"、纯空格、超出 int 范围的大数（防溢出 overflow）
 * 能放行的输入：  "65"、" 65 "（前后带空格）、"-10"、"+3"
 * 返回 1 = 成功解析；0 = 非法
 * ------------------------------------------------------------ */
static int parse_int(const char *s, int *out) {
    long long val = 0;  /* long long 至少 64 位：用大类型先累加，
                         * 还没超出 int 就能提前发现溢出 */
    int negative = 0;

    while (*s == ' ' || *s == '\t') s++;    /* 跳过前导空白（可能多打了空格） */

    if (*s == '+' || *s == '-') { negative = (*s == '-'); s++; }
    if (*s < '0' || *s > '9') return 0;     /* 符号后面没数字 → 非法
                                             * （"+-3"、"-"、"不知道" 全在这拦下） */

    while (*s >= '0' && *s <= '9') {
        val = val * 10 + (*s - '0');        /* 数字字符→数值：'6'-'0'=6（ASCII 原理） */
        s++;
        /* 超出 int 能装的范围就拒绝（正负边界差 1：-2147483648 比 2147483647 多 1） */
        if (val > (negative ? -(long long)INT_MIN : (long long)INT_MAX)) return 0;
    }

    while (*s == ' ' || *s == '\t') s++;    /* 跳过尾部空白 */
    if (*s != '\0') return 0;               /* 数字后面还有东西（"65abc"、"1.5"）→ 非法 */

    *out = negative ? (int)(-val) : (int)val;
    return 1;
}

/* ------------------------------------------------------------
 * ask_int —— 客观题作答：整数校验 + 1 次错误提示 + 1 次重输
 *   min_v/max_v = 合法范围（英文术语: valid range）
 *   *bad        = 回传标记：1 表示最终按无效输入记了 0 分
 * ------------------------------------------------------------ */
static int ask_int(int min_v, int max_v, int *bad) {
    char line[128];
    int value;
    int attempt;
    *bad = 0;

    for (attempt = 0; attempt < 2; attempt++) {  /* 最多读 2 行：首输 + 1 次重输 */
        int st = read_line(line, sizeof(line));

        if (st == 0) {                      /* EOF：输入中断（Ctrl+Z / 管道断开） */
            printf("  输入已结束，本题按 0 分记录\n");
            *bad = 1;
            return 0;
        }
        if (st == 1 && parse_int(line, &value)
            && value >= min_v && value <= max_v) {
            return value;                   /* 合法 → 交卷 */
        }

        /* 非法：第 1 次给错误提示（这是唯一 1 次错误提示），
         * 第 2 次仍非法就不再提示机会，直接记 0 分 */
        if (attempt == 0) {
            if (min_v == INT_MIN && max_v == INT_MAX)
                printf("  输入无效！请输入一个整数（例：65），最后 1 次机会: ");
            else
                printf("  输入无效！请输入 %d ~ %d 的整数，最后 1 次机会: ",
                       min_v, max_v);
        }
    }

    printf("  仍无效，本题按 0 分记录\n");
    *bad = 1;
    return 0;
}

int main(void) {
    system("chcp 65001");   // 切控制台代码页为 UTF-8（英文术语: codepage），防中文乱码

    /* ---- 答案变量：先给确定初值 0，任何路径都不会留栈上垃圾 ---- */
    int a1 = 0, a2 = 0, a3 = 0, a4 = 0, a5 = 0;
    /* 无效输入标记：1 = 该题因输入非法按规则记了 0 分（写进文件备注） */
    int bad1 = 0, bad2 = 0, bad3 = 0, bad4 = 0, bad5 = 0;
    /* 主观题答案：字符数组（英文术语: character array）
     * 256 字节 ≈ 最多 85 个汉字（UTF-8 下 1 汉字 ≈ 3 字节）+ '\0' */
    char answer_zh[256];
    answer_zh[0] = '\0';    /* 先放空串，即使后面 EOF 也是干净的值 */
    int q6_cut = 0;         /* 1 = Q6 答案超长被截断（写文件时追加标注） */

    printf("========== 输入输出考题（共6题）==========\n");
    printf("提示：客观题输入整数（非法会提示 1 次重输），简答题任意文字均可\n\n");

    /* 第 1 题：格式符（考点：printf 的 format string；选择题只认 1~4） */
    printf("Q1. 想打印一个整数，应该用哪个格式符？\n");
    printf("    1) %%d   2) %%f   3) %%c   4) %%s\n");
    printf("你的答案: ");
    a1 = ask_int(1, 4, &bad1);

    /* 第 2 题：ASCII（考点：字符的本质是整数） */
    printf("\nQ2. 字符 'A' 的 ASCII 码值是多少？（输入数字）\n");
    printf("你的答案: ");
    a2 = ask_int(INT_MIN, INT_MAX, &bad2);

    /* 第 3 题：sizeof（考点：类型占几字节） */
    printf("\nQ3. 在你的电脑上 sizeof(int) 是几字节？\n");
    printf("你的答案: ");
    a3 = ask_int(INT_MIN, INT_MAX, &bad3);

    /* 第 4 题：字符串与 \0（考点：字符串占内存含终止符） */
    printf("\nQ4. 字符串 \"abc\" 在内存里占几个字节？（含 '\\0'）\n");
    printf("你的答案: ");
    a4 = ask_int(INT_MIN, INT_MAX, &bad4);

    /* 第 5 题：转义字符（考点：\\n 的字节值） */
    printf("\nQ5. 转义字符 \\n 对应的 ASCII 值是多少？\n");
    printf("你的答案: ");
    a5 = ask_int(INT_MIN, INT_MAX, &bad5);

    /* 第 6 题：主观题 —— 永不拒绝，任何输入原样保留
     * （Q1~Q5 的 ask_int 每次最多消耗 2 行且失败后会清干净，
     *  所以缓冲区到这里一定是干净的，fgets 不会被残渣干扰） */
    printf("\nQ6.【简答】用一句话说明：字符串 \"abc\" 为什么要多占 1 个字节？\n");
    printf("你的答案（任意内容，回车提交）: ");
    int st = read_line(answer_zh, sizeof(answer_zh));
    if (st == 0) {
        strcpy(answer_zh, "(未作答)");              /* EOF：没输入就交卷了 */
    } else if (st == -1) {
        /* 超长：截断部分保不住了，但用标记记录"这答案不完整"。
         * 标记不塞进 answer_zh（缓冲区已满塞不下），改为写文件时追加 */
        q6_cut = 1;
        printf("  警告：答案超过 255 字节，超出部分已被截断\n");
    }
    /* st == 1 → 原样保留；即使是空行（直接回车）也照存，交给审查 */

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
    fprintf(fp, "Q1. 格式符选择     你的答案: %d%s   正确: 1 (%%d)\n",
            a1, bad1 ? " [无效输入按规则记0]" : "");
    fprintf(fp, "Q2. 'A'的ASCII码   你的答案: %d%s   正确: 65\n",
            a2, bad2 ? " [无效输入按规则记0]" : "");
    fprintf(fp, "Q3. sizeof(int)    你的答案: %d%s   正确: 4\n",
            a3, bad3 ? " [无效输入按规则记0]" : "");
    fprintf(fp, "Q4. \"abc\"占几字节  你的答案: %d%s   正确: 4\n",
            a4, bad4 ? " [无效输入按规则记0]" : "");
    fprintf(fp, "Q5. \\n的ASCII值    你的答案: %d%s   正确: 10\n",
            a5, bad5 ? " [无效输入按规则记0]" : "");
    fprintf(fp, "Q6. 主观题简答     你的答案: %s%s\n",
            answer_zh, q6_cut ? " 【超长已截断，原文不完整】" : "");

    fclose(fp);                 // 忘记 fclose → 数据可能还留在缓冲区没写进磁盘

    printf("\n========== 答题结束 ==========\n");
    printf("你的答案已保存到: io-quiz-answers.txt\n");
    printf("（Q1~Q5 对一下文件里的正确答案；Q6 主观题原文保留，交给我审查）\n");

    return 0;   // 0 = 正常结束
}

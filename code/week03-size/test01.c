#include <stdio.h>

int main(void) {
    /* ① 无符号溢出：unsigned char 上限 255，超了绕回 0 */
    unsigned char c = 250;
    c = c + 10;                        // 250+10=260 → 绕回 260-256=4
    printf("250 + 10 = %u\n", c);      // 输出 4

    /* ② 有符号溢出：INT_MAX+1 绕回最小值（C 标准叫"未定义行为"） */
    int big = 2147483647;
    big = big + 1;
    printf("INT_MAX + 1 = %d\n", big); // 输出 -2147483648

    /* ③ 浮点精度：0.1 二进制装不下，0.1f+0.2f 不是精确的 0.3 */
    float a = 0.1f + 0.2f;
    printf("0.1f + 0.2f = %.10f\n", a); // 输出 0.3000000119（%f 只显示6位会隐藏差异）

    return 0;
}

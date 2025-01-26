#include <stdio.h>

// 递归函数：计算拆分方案数，不包括n本身
int count_partitions(int n, int min_factor) {
    int count = 0;
    for (int i = min_factor; i <= n; i++) {
        if (n % i == 0 && i > 1) {
            count += count_partitions(n / i, i);
        }
    }
    return count;
}

int main() {
    int n;

    // 输入自然数
    printf("请输入一个自然数: ");
    scanf("%d", &n);

    // 计算并输出拆分方案数
    int result = count_partitions(n, 2) + 1; // +1 for n itself
    printf("自然数 %d 可以拆分成 %d 个自然数相乘的方案。\n", n, result);

    return 0;
}
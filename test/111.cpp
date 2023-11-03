#include <cstdio>

const int maxn = 1e5 + 5;
int n;
double p[maxn], f[maxn], g[maxn], h[maxn];

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%lf", p + i);
        p[i] = 1 - p[i];
    }
    for (int i = 1; i <= n; i++) {
        f[i] = (f[i - 1] + 1.0) * p[i];
        g[i] = (g[i - 1] + f[i - 1] * 2.0 + 1.0) * p[i];
        h[i]=h[i-1]+(f[i]+g[i]);
    }
    printf("%lf\n", h[n]);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int N;
    if (scanf("%d", &N) != 1) return 0;
    int *val = (int *)malloc(N * sizeof(int));
    int *wt = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &val[i]) != 1) return 0;
    }
    for (int i = 0; i < N; i++) {
        if (scanf("%d", &wt[i]) != 1) return 0;
    }
    int W;
    if (scanf("%d", &W) != 1) return 0;
    int *dp = (int *)calloc(W + 1, sizeof(int));
    for (int i = 0; i < N; i++) {
        for (int w = W; w >= wt[i]; w--) {
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
    printf("%d\n", dp[W]);
    free(val);
    free(wt);
    free(dp);
    return 0;
}


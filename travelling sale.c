#include <stdio.h>
#include <stdlib.h>

#define INF 1e9

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int mask, int pos, int n, int **dist, int **dp) {
    if (mask == (1 << n) - 1) {
        return (dist[pos][0] != -1) ? dist[pos][0] : INF;
    }
    if (dp[mask][pos] != -1) {
        return dp[mask][pos];
    }
    int ans = INF;
    for (int nxt = 0; nxt < n; nxt++) {
        if ((mask & (1 << nxt)) == 0 && dist[pos][nxt] != -1) {
            int newAns = dist[pos][nxt] + tsp(mask | (1 << nxt), nxt, n, dist, dp);
            ans = min(ans, newAns);
        }
    }
    return dp[mask][pos] = ans;
}

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int **dist = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        dist[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &dist[i][j]) != 1) return 0;
        }
    }
    int numStates = 1 << n;
    int **dp = (int **)malloc(numStates * sizeof(int *));
    for (int i = 0; i < numStates; i++) {
        dp[i] = (int *)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++) {
            dp[i][j] = -1;
        }
    }
    int result = tsp(1, 0, n, dist, dp);
    printf("%d\n", result);
    for (int i = 0; i < n; i++) free(dist[i]);
    free(dist);
    for (int i = 0; i < numStates; i++) free(dp[i]);
    free(dp);
    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN 1005
#define MAXK 1005
#define INF -1000000000

int n, k;
int grid[MAXN][3];
int dp[MAXN][8][MAXK];

int max(int a, int b);

int solve(int row, int mask, int tiles_used);

int main() {
    scanf("%d %d", &n, &k);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < 3; ++j)
            scanf("%d", &grid[i][j]);

    for (int i = 0; i <= n; ++i)
        for (int m = 0; m < 8; ++m)
            for (int t = 0; t <= k; ++t)
                dp[i][m][t] = -1;

    int result = solve(0, 0, 0);
    printf("%d\n", result);
    return 0;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int solve(int row, int mask, int tiles_used) {
    if (tiles_used > k) return INF;
    if (row == n) {
        return tiles_used == k ? 0 : INF;
    }

    if (dp[row][mask][tiles_used] != -1) {
        return dp[row][mask][tiles_used];
    }

    int best = solve(row + 1, 0, tiles_used);

    for (int c = 0; c < 2; ++c) {
        if (((mask >> c) & 1) == 0 && ((mask >> (c + 1)) & 1) == 0) {
            int val = grid[row][c] + grid[row][c + 1];
            int new_mask = mask | (1 << c) | (1 << (c + 1));
            best = max(best, val + solve(row, new_mask, tiles_used + 1));
        }
    }

    for (int c = 0; c < 3; ++c) {
        if (((mask >> c) & 1) == 0 && row + 1 < n) {
            int val = grid[row][c] + grid[row + 1][c];
            int new_mask = mask | (1 << c);
            best = max(best, val + solve(row, new_mask, tiles_used + 1));
        }
    }

    dp[row][mask][tiles_used] = best;
    return best;
}

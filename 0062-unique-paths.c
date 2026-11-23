// 62. Unique Paths (Medium)
// https://leetcode.com/problems/unique-paths/

int uniquePaths(int m, int n) {
    long long dp[n];
    for (int i = 0; i < n; i++) dp[i] = 1;
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            dp[j] += dp[j - 1];
        }
    }
    return dp[n - 1];
}

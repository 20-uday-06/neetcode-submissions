class Solution {
public:
    int dfs(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {

        if (dp[i][j] != -1)
            return dp[i][j];

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        int best = 1;

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 ||
                ni >= matrix.size() ||
                nj >= matrix[0].size())
                continue;

            if (matrix[ni][nj] > matrix[i][j]) {
                best = max(
                    best,
                    1 + dfs(ni, nj, matrix, dp)
                );
            }
        }

        return dp[i][j] = best;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(
            n, vector<int>(m, -1)
        );

        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                ans = max( ans,dfs(i, j, matrix, dp));
            }
        }

        return ans;
    }
};
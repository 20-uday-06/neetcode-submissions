class Solution {
public:
    int ans = 1;

    void dfs(int i, int j,
             vector<vector<int>>& matrix,
             vector<vector<int>>& dist) {

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int ni = i + dx[k];
            int nj = j + dy[k];

            if (ni < 0 || nj < 0 ||
                ni >= matrix.size() ||
                nj >= matrix[0].size())
                continue;

            if (matrix[ni][nj] > matrix[i][j]) {

                if (dist[ni][nj] < dist[i][j] + 1) {

                    dist[ni][nj] = dist[i][j] + 1;

                    ans = max(ans, dist[ni][nj]);

                    dfs(ni, nj, matrix, dist);
                }
            }
        }
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {

        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dist(n, vector<int>(m, 1));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dfs(i, j, matrix, dist);
            }
        }

        return ans;
    }
};
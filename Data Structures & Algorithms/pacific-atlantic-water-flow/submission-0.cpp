class Solution {
public:

    void atlantic(vector<vector<int>> &heights,
                  vector<vector<int>> &atlant) {

        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> q;

        // Bottom row
        for(int j = 0; j < m; j++) {
            q.push({n - 1, j});
            atlant[n - 1][j] = 1;
        }

        // Right column
        for(int i = 0; i < n; i++) {
            if(atlant[i][m - 1] == 0) {
                q.push({i, m - 1});
                atlant[i][m - 1] = 1;
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = x + dx[k];
                int nc = y + dy[k];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if(atlant[nr][nc] == 0 &&
                   heights[nr][nc] >= heights[x][y]) {

                    q.push({nr, nc});
                    atlant[nr][nc] = 1;
                }
            }
        }
    }


    void pacific(vector<vector<int>> &heights,
                 vector<vector<int>> &paci) {

        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int,int>> q;

        // Top row
        for(int j = 0; j < m; j++) {
            q.push({0, j});
            paci[0][j] = 1;
        }

        // Left column
        for(int i = 0; i < n; i++) {
            if(paci[i][0] == 0) {
                q.push({i, 0});
                paci[i][0] = 1;
            }
        }

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        while(!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for(int k = 0; k < 4; k++) {

                int nr = x + dx[k];
                int nc = y + dy[k];

                if(nr < 0 || nc < 0 || nr >= n || nc >= m)
                    continue;

                if(paci[nr][nc] == 0 &&
                   heights[nr][nc] >= heights[x][y]) {

                    q.push({nr, nc});
                    paci[nr][nc] = 1;
                }
            }
        }
    }


    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>> paci(n, vector<int>(m, 0));
        vector<vector<int>> atlant(n, vector<int>(m, 0));

        vector<vector<int>> ans;

        pacific(heights, paci);
        atlantic(heights, atlant);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {

                if(paci[i][j] == 1 && atlant[i][j] == 1) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};
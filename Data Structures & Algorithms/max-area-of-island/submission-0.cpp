class Solution {
public:
    void dfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int i, int j , int area) {
        if (vis[i][j] != -1) {
            return;
        }
        if (grid[i][j] == 0) return;

        vis[i][j] = 1;
        area++;

        int dx[] = {0, 1, 0, -1};
        int dy[] = {1, 0, -1, 0};

        for (int k = 0; k < 4; k++) {
            int nr = i + dx[k];
            int nc = j + dy[k];

            if (nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() &&
                grid[nr][nc] == '1') {
                dfs(vis, grid, nr, nc , area);
            }
        }
    }

    int bfs(vector<vector<int>>& vis, vector<vector<int>>& grid , int i , int j) {
        queue<pair<int,int>> q;

        int area = 1;

        q.push({i,j});
        vis[i][j] = 1;

        while(!q.empty()){
            auto [x , y] = q.front();
            q.pop();

            int dx[] = {0, 1, 0, -1};
            int dy[] = {1, 0, -1, 0};

            for(int k = 0 ; k < 4 ; k++){
                int nr = x + dx[k];
                int nc = y + dy[k];

                if(nr >= 0 && nc >= 0 && nr < grid.size() && nc < grid[0].size() && grid[nr][nc] == 1){
                    if(vis[nr][nc] != -1) continue;
                    q.push({nr , nc});
                    vis[nr][nc] =1;
                    area++;
                }
            }
        }
        return area;

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), -1));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (vis[i][j] == -1 && grid[i][j] == 1) {
                    // dfs(vis, grid, i, j);
                    ans = max(ans , bfs(vis , grid , i , j));
                }
            }
        }
        return ans;
    }
};

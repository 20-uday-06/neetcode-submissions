class Solution {
public:
    void bfs(vector<vector<int>> & grid , queue<pair<int,int>> &q){
        int n = grid.size();
        int m = grid[0].size();

        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();

            int dx[] = {0 , 1 , 0 , -1};
            int dy[] = {1 , 0 , -1 , 0};

            for(int k =0 ; k < 4 ; k++){
                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] !=-1 && grid[nr][nc] != 0){
                    if(grid[nr][nc] > grid[row][col] + 1){
                        grid[nr][nc] = grid[row][col] +1;
                        q.push({nr ,nc});
                    }
                }
            }
        }
    }
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 0){
                    q.push({i , j});
                }
            }
        }
        bfs(grid , q);
    }
};

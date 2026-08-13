class Solution {
public:
    vector<vector<int>> bfs(vector<vector<int>> & grid , queue<pair<int,int>> &q){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n , vector<int>(m , INT_MAX));

        for(int i =0 ; i < n ; i++){
            for(int j =0 ; j < m ; j++){
                if(grid[i][j] == 2) dist[i][j] = 0;
            }
        }

        while(!q.empty()){
            auto [row , col] = q.front();
            q.pop();

            int dx[] = {0 , 1 , 0 , -1};
            int dy[] = {1 , 0 , -1 , 0};

            for(int k =0 ; k < 4 ; k++){
                int nr = row + dx[k];
                int nc = col + dy[k];

                if(nr >= 0 && nc >= 0 && nr < n && nc < m && grid[nr][nc] !=0){
                    if(dist[nr][nc] > dist[row][col] + 1){
                        dist[nr][nc] = dist[row][col] +1;
                        q.push({nr ,nc});
                    }
                }
            }
        }
        return dist;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i = 0; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
            }
        }

        vector<vector<int>> dist = bfs(grid,q);

        int ans = 0;

        for(int i = 0 ; i < grid.size() ; i ++){
            for(int j =0 ; j < grid[0].size() ; j++){
                if(dist[i][j] == INT_MAX && grid[i][j] == 1) return -1;
                if(grid[i][j] ==1 )ans = max(ans , dist[i][j]);
            }
        }
        return ans;  
    }
};

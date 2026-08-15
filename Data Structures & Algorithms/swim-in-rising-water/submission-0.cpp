class Solution {
public:
    void bfs(vector<vector<int>> &grid , vector<vector<int>> & dist){
        int n = grid.size();
        int m = grid[0].size();

        int maxi = 0;
        
        queue<pair<int,int>> q;
        dist[0][0] = grid[0][0];
        q.push({0,0});

        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();

            int dx[] = {0 , 1 , 0 , -1};
            int dy[] = {1 , 0 , -1 , 0};

            for(int k = 0 ; k < 4 ; k++){
                int nr = x + dx[k];
                int nc = y + dy[k];

                if(!(nr >= 0 && nc >= 0 && nr < n && nc < m)) continue;

                maxi = max(grid[nr][nc] , dist[x][y]);

                if(maxi < dist[nr][nc]){
                    dist[nr][nc] = maxi;
                    q.push({nr , nc});
                }
            }
        }
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n , vector<int> (m , INT_MAX));
        bfs(grid , dist);
        return dist[n-1][m-1];
    }
};

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,1e9));

        q.push({0,0});
        dist[0][0] = grid[0][0];

        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int k =0 ; k <4 ; k++){
                int nr = r + dx[k];
                int nc = c + dy[k];

                if(!(nr >= 0 && nc >= 0 && nr < n && nc < m)) continue;

                int time = max(grid[nr][nc] , dist[r][c]);

                if(time < dist[nr][nc]){
                    dist[nr][nc] = time;
                    q.push({nr,nc});
                }
            }
        }
        return dist[n-1][m-1];
    }
};

class Solution {
   public:
    bool dfs(vector<vector<int>>& adj, int node, vector<int>& vis, int parent) {
        vis[node] = 1;

        for (auto nei : adj[node]) {
            if (!vis[nei]) {
                if (!dfs(adj, nei, vis, node)) return false;
            } else if (nei != parent)
                return false;
        }
        
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        // make adj list
        vector<vector<int>> adj(n);
        vector<int> vis(n , 0);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        bool cycle = dfs(adj , 0 , vis , -1);

        if(!cycle) return false;

        for(int i = 0 ; i < n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};

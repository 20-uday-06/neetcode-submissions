class Solution {
   public:
    void travel(int k, vector<vector<pair<int,int>>>& adj, vector<int> &dist) {
        set <pair<int ,int>> st; // {distance, node}

        st.insert({0 , k});
        dist[k] = 0;

        while(!st.empty()){
            auto [distance , node] = *st.begin();
            st.erase(st.begin());

            if(distance > dist[node]) continue;

            for(auto [v,t] : adj[node]){

                if(distance + t < dist[v]){
                    dist[v] = distance + t;
                    st.insert({dist[v] , v});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n+1 , INT_MAX);
        vector<vector<pair<int,int>>> adj(n+1); // 1 -> [{v,t} , {v,t}] , 2 ->[{v,t} , {v,t}]

        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int t = it[2];

            adj[u].push_back({v , t});
        }
        travel(k , adj, dist);

        int ans = INT_MIN;

        dist[0] = 0;

        for(int it : dist){
            if(it == INT_MAX) return -1;
            ans = max (ans , it);
        }
        return ans;
    }
};

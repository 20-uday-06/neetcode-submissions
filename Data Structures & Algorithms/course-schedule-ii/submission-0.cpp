class Solution {
   public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& pathVis,
             stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                if (!dfs(neighbor, adj, vis, pathVis, st)) return false;
            } else if (pathVis[neighbor]) {
                return false;
            }
        }

        pathVis[node] = 0;

        st.push(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        // [a, b] => b -> a
        for (auto& p : prerequisites) {
            int a = p[0];
            int b = p[1];

            adj[b].push_back(a);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        stack<int> st;

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(i, adj, vis, pathVis, st)) return {};
            }
        }

        vector<int> ans;

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};
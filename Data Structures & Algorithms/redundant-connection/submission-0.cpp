class Solution {
public:

    vector<int> parent;
    vector<int> sz;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    bool unite(int u, int v) {

        u = find(u);
        v = find(v);

        if(u == v)
            return false;

        if(sz[u] < sz[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else {
            parent[v] = u;
            sz[u] += sz[v];
        }

        return true;
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n = edges.size();

        parent.resize(n + 1);
        sz.assign(n + 1, 1);

        for(int i = 1; i <= n; i++) {
            parent[i] = i;
        }

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(!unite(u, v)) {
                return {u, v};
            }
        }

        return {};
    }
};
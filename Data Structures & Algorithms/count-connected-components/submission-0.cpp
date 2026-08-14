class Solution {
public:

    vector<int> parent;
    vector<int> sz;

    int find(int x) {
        if(parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int u, int v) {

        u = find(u);
        v = find(v);

        if(u == v)
            return;

        // Attach smaller component to larger component
        if(sz[u] < sz[v]) {
            parent[u] = v;
            sz[v] += sz[u];
        }
        else {
            parent[v] = u;
            sz[u] += sz[v];
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        parent.resize(n);
        sz.assign(n, 1);

        for(int i = 0; i < n; i++) {
            parent[i] = i;
        }

        int components = n;

        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            if(find(u) != find(v)) {
                unite(u, v);
                components--;
            }
        }

        return components;
    }
};
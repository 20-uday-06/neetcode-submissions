class Solution {
public:

    map<string, multiset<string>> adj;
    vector<string> result;

    void dfs(string airport) {

        while (!adj[airport].empty()) {

            string next = *adj[airport].begin();

            adj[airport].erase(adj[airport].begin());

            dfs(next);
        }

        result.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {

        for (auto& ticket : tickets) {
            adj[ticket[0]].insert(ticket[1]);
        }

        dfs("JFK");

        reverse(result.begin(), result.end());

        return result;
    }
};
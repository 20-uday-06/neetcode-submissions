class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();

        vector<int> minDist(n, INT_MAX);
        vector<bool> visited(n, false);

        minDist[0] = 0;

        int totalCost = 0;

        for (int i = 0; i < n; i++) {

            int node = -1;

            for (int j = 0; j < n; j++) {
                if (!visited[j] && 
                    (node == -1 || minDist[j] < minDist[node])) {
                    node = j;
                }
            }

            visited[node] = true;
            totalCost += minDist[node];

            for (int j = 0; j < n; j++) {
                if (!visited[j]) {
                    int distance =
                        abs(points[node][0] - points[j][0]) +
                        abs(points[node][1] - points[j][1]);

                    minDist[j] = min(minDist[j], distance);
                }
            }
        }

        return totalCost;
    }
};
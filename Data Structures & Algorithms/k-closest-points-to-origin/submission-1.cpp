class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            int da = a.first * a.first + a.second * a.second;
            int db = b.first * b.first + b.second * b.second;

            return da > db;
        }
    };

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue <pair<int,int> , vector<pair<int,int>> , Compare> pq;

        for(auto it : points) pq.push({it[0] , it[1]});

        vector<vector<int>> ans;

        for(int i = 0 ; i < k ; i++){
            auto [x , y] = pq.top();
            pq.pop();
            ans.push_back({x , y});
        }
        return ans;
    }
};

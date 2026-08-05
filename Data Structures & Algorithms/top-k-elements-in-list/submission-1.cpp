class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        map<int, int> mp;  // {number, frequency}

        for (int x : nums) {
            mp[x]++;
        }

        vector<pair<int, int>> v;
        vector<int> ans;

        for (auto [num, freq] : mp) {
            v.push_back({freq, num});
        }

        sort(v.rbegin(), v.rend());

        for (int i = 0; i < k; i++) {
            ans.push_back(v[i].second);
        }

        return ans;
    }
};
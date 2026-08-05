class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map <int,int> mp; // {num , index}
        for(int i  = 0 ; i < n ; i++){
            int remaining = target - nums[i];
            if(mp.find(remaining) != mp.end()){
                return {mp[remaining] , i};
            }
            mp.insert({nums[i] , i});
        }
        return {-1};

    }
};

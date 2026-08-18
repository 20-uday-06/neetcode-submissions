class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int mini = nums[0];
        int maxi = nums[0];
        int ans = nums[0];

        for(int j = 1 ; j <nums.size() ; j++){
            int i = nums[j];
            int tempMax = maxi;

            maxi = max({i , i*maxi , i*mini});
            mini = min({i , i*tempMax , i*mini});

            ans = max(maxi , ans);
        }
        return ans;
    }
};

class Solution {
public:
    int solve(int i , vector<int> &nums , vector<int> &dp){
        //base case
        if(i>=nums.size()) return 0;

        //dp check
        if(dp[i] != -1) return dp[i];

        //choices
        int take = nums[i] + solve(i+2 , nums , dp);
        int notTake = solve(i+1 , nums , dp);

        //return
        return dp[i] = max(take , notTake);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+1 , -1);
        return solve(0 , nums ,dp);
    }
};

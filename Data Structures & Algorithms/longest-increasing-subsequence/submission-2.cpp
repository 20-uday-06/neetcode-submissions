class Solution {
public:
    int solve(int i , int prev , vector<int>&nums , vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][prev+1] != -1) return dp[i][prev+1];

        if(prev == -1 || nums[i] > nums[prev]){
            int take = 1 + solve(i+1 , i , nums , dp);
            int notTake = solve(i+1 , prev , nums , dp);
            return dp[i][prev+1] =  max(take , notTake);
        }
        return dp[i][prev+1] = solve(i+1 , prev , nums , dp);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp (nums.size() , vector<int>(nums.size()+1 , -1));
        return solve(0 , -1 , nums , dp);
    }
};

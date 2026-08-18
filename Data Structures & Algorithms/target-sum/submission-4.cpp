class Solution {
public:
    int solve(int i , int target,int sumi, vector<int> &nums , vector<vector<int>> &dp){
        if(target == 0 && i==nums.size()) return 1;
        if(i==nums.size()) return 0;
        if(abs(target) > sumi) return 0;

        if(dp[i][target+sumi] != -1) return dp[i][target+sumi];

        int sum = solve(i+1 ,target+nums[i] ,sumi , nums ,dp);
        int diff = solve(i+1 , target-nums[i],sumi , nums , dp);

        return dp[i][target+sumi] = sum + diff;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int sumi = 0;
        for(int i : nums) sumi+=i;
        vector<vector<int>> dp (nums.size() , vector<int>(2*sumi +1 , -1));
        return solve(0 , target , sumi , nums , dp);
    }
};

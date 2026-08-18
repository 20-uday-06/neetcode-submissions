class Solution {
public:
    bool solve(int i , int target , vector<int> &nums , vector<vector<int>> &dp){
        if(target == 0) return true;
        if(target <0) return false;
        if(i == nums.size()) return false;

        if(dp[i][target] != -1) return dp[i][target];

        bool take = solve(i+1 , target - nums[i] , nums , dp);
        bool notTake = solve(i+1 , target , nums , dp);

        return dp[i][target] = take||notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sumi = 0 , target = 0;
        for(int i : nums) sumi += i;
        target = sumi/2;
        vector<vector<int>> dp (nums.size() , vector<int> (target +1 , -1));
        if(sumi%2 != 0) return false;
        return solve(0 , target , nums ,dp);
    }
};

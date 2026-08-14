class Solution {
public:
    int solve(int i , vector<int> & cost , vector<int> &dp){
        //base case
        if(i>=cost.size()) return 0;

        //dp check
        if(dp[i] != -1) return dp[i];

        //choices
        int one = solve(i+1 , cost , dp);
        int two = solve(i+2 , cost , dp);

        //return
        return dp[i] = cost[i] + min(one ,two);

    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int>  dp(n,-1);
        return min(solve(0 , cost , dp) , solve(1 , cost , dp));
    }
};

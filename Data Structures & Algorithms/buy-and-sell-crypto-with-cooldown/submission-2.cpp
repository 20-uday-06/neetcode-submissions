class Solution {
   public:
    int solve(int i, bool bought, vector<int>& prices, vector<vector<int>>& dp) {
        if (i >= prices.size()) return 0;
        if (dp[i][bought] != -1) return dp[i][bought];

        // bought == true means i have one , i.e.. i can only sell

        if (bought) {
            return dp[i][bought] = max(+prices[i] + solve(i + 2, false, prices, dp),
                                       solve(i + 1, true, prices, dp));
        }

        return dp[i][bought] = max(-prices[i] + solve(i + 1, true, prices, dp),
                                       solve(i + 1, false, prices, dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp (prices.size()+1 , vector<int>(2 ,-1));
        return solve(0 , false , prices , dp);
    }
};

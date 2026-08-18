class Solution {
public:
    int solve(int i, int amount, vector<int> & coins , vector<vector<int>> &dp){
        if(amount ==0) return 0;
        if(i == coins.size()) return 1e9;

        if(dp[i][amount] != -1) return dp[i][amount];

        int take = 1e9;
        if(coins[i] <= amount)
        take = 1 + solve(i , amount-coins[i] , coins , dp);
        int notTake= solve(i+1 , amount , coins , dp);

        return dp[i][amount] =  min(take , notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>> dp (coins.size()+1 , vector<int> (amount+1 , -1));
        int ans = solve(0 , amount , coins ,dp);
        return ans == 1e9 ? -1 : ans;
    }
};

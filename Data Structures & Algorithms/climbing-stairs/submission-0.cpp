class Solution {
public:
    int dpe(int i , int n, vector<int> &dp){
        //if reached , count it as 1 way
        if(i==n) return 1;
        if(i>n) return 0;

        //check dp
        if(dp[i] != -1) return dp[i];

        int one = dpe(i+1 , n , dp);
        int two = dpe(i+2 , n ,dp);

        return dp[i] = one + two;

    }
    int climbStairs(int n) {
        vector<int> dp(n , -1);
        return dpe(0 , n , dp);
    }
};

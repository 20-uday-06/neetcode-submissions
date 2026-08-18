class Solution {
public:
    int solve(int i , int j , string &str1 , string&str2 , vector<vector<int>> &dp){
        if(i == str1.size() || j == str2.size()) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int take = 0;
        if(str1[i] == str2[j]){
            take = 1 + solve(i+1 , j+1 , str1 , str2 , dp);
        }
        int notTake = max(solve(i+1 , j , str1 , str2 , dp) , solve(i , j+1 , str1 , str2 , dp));

        return dp[i][j] = max(take , notTake);
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.size() , vector<int> (text2.size() , -1));
        return solve(0 , 0 , text1 , text2 , dp);
    }
};

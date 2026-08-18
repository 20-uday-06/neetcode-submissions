class Solution {
public:
    int solve(int i , int j , string& s , string&t , vector<vector<int>>&dp){
        if(i==s.size() && j==t.size()) return 0;
        if(i==s.size()) return t.size() - j;
        if(j ==t.size()) return s.size()-i;
        
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i]==t[j]){
            return dp[i][j] = solve(i+1 , j+1 , s , t , dp);
        }
        return dp[i][j] = 1+ min({
            solve(i , j+1 , s , t , dp), //insert
            solve(i+1 , j , s , t , dp), //delete
            solve(i+1 , j+1 , s , t , dp)
        });
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size()+1 , vector<int>(word2.size()+1 , -1));
        return solve(0,0,word1,word2,dp);
    }
};

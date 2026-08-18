class Solution {
public:
    bool solve(int i , int j , string& s , vector<vector<int>> &dp){
        if(i>=j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = false;
        return dp[i][j] = solve(i+1 , j-1 , s , dp);
    }
    int countSubstrings(string s) {
        int ans = 0;
        vector<vector<int>> dp (s.size() , vector<int>(s.size() , -1));
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                if(solve(i , j , s , dp)) ans++;
            }
        }
        return ans;
    }
};

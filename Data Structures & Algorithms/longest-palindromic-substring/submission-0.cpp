class Solution {
public:
    bool solve(int i , int j , string& s , vector<vector<int>> &dp){
        if(i>=j) return true;
        if(dp[i][j] != -1) return dp[i][j];
        if(s[i] != s[j]) return dp[i][j] = false;
        return dp[i][j] = solve(i+1 , j-1 , s , dp);
    }
    string longestPalindrome(string s) {
        int maxLen = 0;
        pair<int,int> p;
        vector<vector<int>> dp (s.size() , vector<int>(s.size() , -1));
        for(int i = 0 ; i < s.size() ; i++){
            for(int j = i ; j < s.size() ; j++){
                if(solve(i , j , s , dp)){
                    if(j-i+1 > maxLen){
                        maxLen = j-i+1;
                        p = {i , j};
                    }
                }
            }
        }
        return s.substr(p.first , maxLen);
    }
};

class Solution {
public:
    bool solve(int i , int j ,string& s1 , string&s2,string &s3 , vector<vector<int>> &dp){
        if(i+j == s3.size()) return true;

        if(dp[i][j] != -1) return dp[i][j];

        int k = i+j;

        //choices
        bool choice1 = false;
        bool choice2 = false;

        if(i<s1.size() && s1[i] == s3[k]){
            choice1 = solve(i+1 , j , s1 ,s2 , s3 , dp);
        }
        if(j<s2.size() && s2[j] == s3[k]){
            choice2 = solve(i , j+1 ,s1 , s2 , s3 , dp);
        }
        return dp[i][j] = choice1 || choice2;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(s1.size()+1 , vector<int>(s2.size()+1 , -1));
        return solve(0 , 0 , s1 , s2 , s3 , dp);
    } 
};

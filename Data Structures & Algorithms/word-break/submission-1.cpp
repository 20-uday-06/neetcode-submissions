class Solution {
public:
    bool solve(int i , string&s , unordered_set<string>& dict , vector<int> &dp){
        if(i==s.size()) return true;

        string check ="";

        if(dp[i] != -1) return dp[i];
        
        for(int j = i ; j < s.size() ; j++){
            check += s[j];
            if(dict.count(check)){
                if(solve(j+1 , s , dict , dp)) return true;
            }
        }
        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> dict (wordDict.begin() , wordDict.end());
        vector<int> dp(s.size(), -1);
        return solve(0 , s , dict ,dp);

    }
};

class Solution {
public:
    int solve(string &s, int i, vector<int> &dp) {
        if (i == s.size()) return 1;

        if (s[i] == '0') return 0;

        if (dp[i] != -1) return dp[i];

        int takeOne = solve(s, i + 1, dp);

        int takeTwo = 0;

        if (i + 1 < s.size()) {
            int x = stoi(s.substr(i, 2));

            if (x >= 10 && x <= 26) {
                takeTwo = solve(s, i + 2, dp);
            }
        }

        return dp[i] = takeOne + takeTwo;
    }

    int numDecodings(string s) {
        vector<int> dp(s.size(), -1);
        return solve(s, 0, dp);
    }
};
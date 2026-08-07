class Solution {
   public:
    bool check2(vector<int>& str1, vector<int>& str2) {
        for (int i = 0; i < 128; i++) {
            if (str1[i] > str2[i]) return false;
        }
        return true;
    }

    string minWindow(string s, string t) {
        pair<int, int> p;
        string s1 = t;  // small
        string s2 = s;  // larger
        if (s1.size() > s2.size()) return "";
        vector<int> str1(128, 0);
        vector<int> str2(128, 0);
        for (char c : s1) {
            str1[c]++;
        }
        int i = 0;
        int j = s1.size() - 1;

        // calc freq of starting element
        for (int i = 0; i < s1.size(); i++) {
            str2[s2[i]]++;
        }

        int ans = INT_MAX;
        int temp = 0;
        int start = 0;

        while (j < s2.size()) {
            while (check2(str1, str2)) {
                temp = j-i+1;
                if(temp < ans){
                    ans = temp;
                    p={i , j};
                }
                str2[s2[i]]--;
                i++;
            }
            j++;
            if(j< s2.size())str2[s2[j]]++;
        }
        string a;
        if(ans == INT_MAX) return "";
        for (int i = p.first; i <= p.second; i++) {
            a += s[i];
        }
        return a;
    }
};

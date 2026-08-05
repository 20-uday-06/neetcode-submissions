class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> str1 (26 , 0);
        vector<int> str2 (26 , 0);

        for(auto i : s){
            str1[i-'a']++;
        }
        for(char i : t){
            str2[i-'a']++;
        }
        for(int i =0 ; i < 26 ; i++){
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }
};

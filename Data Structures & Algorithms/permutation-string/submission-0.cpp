class Solution {
public:
    bool check(int i , int j ,string s2  , vector<int> & str1){
        vector<int> str2 (26 , 0);
        for(int k = i ; k <= j ; k++){
            str2[s2[k] - 'a'] ++;
            // if(str1[k] != str2[k]) return false;
        }
        for(int i = 0 ; i < 26 ; i++){
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) {
        vector<int> str1 (26 , 0);
        for(char c : s1){
            str1[c-'a']++;
        }
        int i =0;
        int j = s1.size()-1;

        while(j < s2.size()){
            if(check(i , j , s2 , str1)) return true;
            i++;
            j++;
        }
        return false;
    }
};

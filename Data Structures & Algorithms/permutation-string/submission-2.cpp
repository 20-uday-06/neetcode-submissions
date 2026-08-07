class Solution {
public:

    bool check2(vector<int> &str1 ,vector<int>&str2){
        for(int i = 0 ; i < 26 ; i++){
            if(str1[i] != str2[i]) return false;
        }
        return true;
    }

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
        if(s1.size() > s2.size()) return false;
        vector<int> str1 (26 , 0);
        vector<int> str2 (26 , 0);
        for(char c : s1){
            str1[c-'a']++;
        }
        int i =0;
        int j = s1.size()-1;

        //calc freq of starting element
        for(int i = 0 ; i < s1.size() ; i++){
            str2[s2[i]-'a']++;
        }

        while(j < s2.size()){
            if(check2(str1 , str2)) return true;
            str2[s2[i]-'a']--;
            i++;
            j++;
            if(j<s2.size()) str2[s2[j]-'a']++;
        }
        return false;
    }
};

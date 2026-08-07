class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        set <char> st;
        int tempSize = 1;
        int maxSize = 1;
        int n = s.length();
        int i = 0;
        int j = 1;
        st.insert(s[i]);
        while(i< n && j < n){
            if(st.find(s[j]) == st.end()){
                tempSize++;
                st.insert(s[j]);
                j++;
            }
            else{
                while(st.find(s[j]) != st.end()){
                    st.erase(s[i]);
                    i++;
                    tempSize--;
                }
            }
            maxSize = max(maxSize , tempSize);
        }
        return maxSize;
    }
};

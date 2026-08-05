class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map <vector<int> , vector<string>> mp; //{freqVector , String}

        for(auto it : strs){
            vector<int> tempFreq(26);
            for(char st : it){
                tempFreq[st-'a']++;
            }
            mp[tempFreq].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto it : mp){
            ans.push_back(it.second);
        }
        // for(auto it : mp){
        //     vector<int> freq = it.first;
        //     string str = it.second;
        //     vector<string> temp;
        //     while(mp.find(freq) != mp.end()){
        //         temp.push_back(mp[freq]);
        //     }
        //     ans.push_back(temp);
        // }
        return ans;
    }
};

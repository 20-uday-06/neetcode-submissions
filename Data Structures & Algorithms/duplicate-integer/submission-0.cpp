class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        bool once = false;
        map <int , int> m;
        for(int i = 0 ; i < nums.size();i++){
            m[nums[i]]++;
        }
        for(auto i : m){
            if(i.second > 1){
                once = true;
            }
        }
        return once;
    }
};
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map <int , int> hashmap;
        for(int i = 0 ; i < nums.size() ; i++){
            int find = target - nums[i];
            if(hashmap.find(find)!=hashmap.end()){
                return {hashmap[find] , i};
            }
            else{
                hashmap.insert({nums[i],i});
            }
        }
    }
};

class Solution {
public:
    void back(vector<int> & nums , int start , vector<vector<int>> & ans , vector<int> & curr){
        ans.push_back(curr);

        for(int i = start ; i < nums.size() ; i++){
            if(i > start && nums[i-1] == nums[i]) continue;

            curr.push_back(nums[i]);
            back(nums , i+1 , ans , curr);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<vector<int>> ans;
        vector<int> curr;
        back(nums , 0 , ans , curr);
        return ans;
    }
};

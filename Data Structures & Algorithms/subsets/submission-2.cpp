class Solution {
public:
    void backtrack(int i , vector<int> & nums , vector<vector<int>>& ans ,vector<int>& curr){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }

        //take it
        curr.push_back(nums[i]);
        backtrack(i+1 , nums , ans , curr);
        curr.pop_back();

        //dont take it
        backtrack(i+1 , nums , ans , curr);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        backtrack(0 , nums , ans , curr);
        return ans;
    }
};

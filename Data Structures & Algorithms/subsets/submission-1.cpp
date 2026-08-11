class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void backtrack(int i , vector<int> & nums){
        if(i==nums.size()){
            ans.push_back(curr);
            return;
        }

        //take it
        curr.push_back(nums[i]);
        backtrack(i+1 , nums);
        curr.pop_back();

        //dont take it
        backtrack(i+1 , nums);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0 , nums);
        return ans;
    }
};

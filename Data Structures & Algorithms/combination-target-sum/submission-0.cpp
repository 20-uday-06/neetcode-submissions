class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;
    void back(vector<int> & nums ,  int sum , int i , int target){
        //base case
        if(sum == target){
            ans.push_back(curr);
            return;
        }
        if(i== nums.size()) return;
        if(sum > target) return;

        //take it
        curr.push_back(nums[i]);
        back(nums , sum + nums[i] , i , target);
        curr.pop_back();

        //dont take it
        back(nums , sum , i+1 , target);
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        back(nums , 0 , 0 , target);
        return ans;
    }
};

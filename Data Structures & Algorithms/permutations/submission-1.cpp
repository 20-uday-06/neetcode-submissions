class Solution {
public:
    vector<int> curr;
    vector<vector<int>> ans;
    vector<bool> used;

    void back(vector<int> &nums , int i){
        if(curr.size() == nums.size()){
            ans.push_back(curr);
            return;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            if(used[i]) continue;

            used[i] = true;
            curr.push_back(nums[i]);
            back(nums , i+1);
            curr.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        used.resize(nums.size() , false);
        back(nums , 0);
        return ans;
    }
};

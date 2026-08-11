class Solution {
public:
    vector<vector<int>> ans;
    vector<int> curr;

    void back(vector<int>& nums, int target, int i) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        for (int j = i; j < nums.size(); j++) {

            if (j > i && nums[j] == nums[j - 1])
                continue;

            if (nums[j] > target)
                break;

            curr.push_back(nums[j]);

            back(nums, target - nums[j], j + 1);

            curr.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        back(candidates, target, 0);

        return ans;
    }
};
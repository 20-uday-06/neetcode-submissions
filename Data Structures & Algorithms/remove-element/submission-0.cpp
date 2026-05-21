class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        int end = nums.size() - 1;

        while (i <= end) {
            if (nums[i] == val) {
                nums[i] = nums[end];
                end--;
            } 
            else {
                i++;
            }
        }

        return end + 1;
    }
};
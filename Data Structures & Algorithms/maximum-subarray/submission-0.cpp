class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = INT_MIN;
        int sumi = 0;
        for(int i : nums){
            sumi += i;
            ans = max(ans , sumi);
            if(sumi<0) sumi = 0;
        }
        return ans;
    }
};

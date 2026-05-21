class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int num = 0;
        int count = 0;
        for(auto i : nums){
            if(count == 0){
                num = i;
            }
            if(i ==num){
                count++;
            }
            else{
                count--;
            }
            
        }
        return num;
    }
};
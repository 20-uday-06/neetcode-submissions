class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // map <int , int> hashmap;
        // for(int i = 0 ; i < nums.size() ; i++){
        //     int find = target - nums[i];
        //     if(hashmap.find(find)!=hashmap.end()){
        //         return {hashmap[find] , i};
        //     }
        //     else{
        //         hashmap.insert({nums[i],i});
        //     }
        // }
        // --------------------TWO POINTER-------------------
        vector<pair<int,int>> arr;

        for(int i = 0; i < nums.size(); i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end());

        int left = 0;
        int right = arr.size() - 1;

        while(left < right){

            int sum = arr[left].first + arr[right].first;

            if(sum == target){
                return {
    min(arr[left].second, arr[right].second),
    max(arr[left].second, arr[right].second)
};
            }

            else if(sum < target){
                left++;
            }

            else{
                right--;
            }
        }

        return {};

    }
};

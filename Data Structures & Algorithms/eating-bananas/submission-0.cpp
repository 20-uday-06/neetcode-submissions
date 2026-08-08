class Solution {
public:
    int calculateHours (int k , vector<int> &piles){
        int hours = 0;
        for(int i : piles) hours += (i + k - 1) / k;
        return hours;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxElement = 0;
        for(int i : piles){
            maxElement = max(maxElement , i);
        }
        int left = 1;
        int right = maxElement ;
        int ans = INT_MAX;

        while(left <= right){
            int mid = left + (right-left)/2;

            int hours = calculateHours(mid , piles);

            if(hours > h){
                left = mid+1;
            }
            else{
                right = mid-1;
                ans= min(ans , mid);
            }
        }
        return ans;

    }
};

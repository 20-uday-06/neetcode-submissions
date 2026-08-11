class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int> pq;
        int ans = 0;
        
        for(int i : nums) pq.push(i);
        for(int i = 0 ; i < k ; i++){
            ans = pq.top();
            pq.pop();
        }
        return ans;
    }
};

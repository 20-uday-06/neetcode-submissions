class KthLargest {
public:
    int K;
    priority_queue <int> temp;
    priority_queue <int , vector<int> , greater<int>> pq;

    KthLargest(int k, vector<int>& nums) {
        K=k;
        for(int i : nums){
            temp.push(i);
        }
        for(int i = 0 ; i < k && !temp.empty(); i++){
            pq.push(temp.top());
            temp.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size() >K ) pq.pop();
        return pq.top();
    }
};

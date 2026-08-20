class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int diff = 0;
        int curr = 0;
        int n = gas.size();
        int ans = 0;

        int gastotal = 0;
        int costtotal = 0;

        for(int i = 0 ; i < n ; i++){
            gastotal += gas[i];
            costtotal += cost[i];
        }
        if(gastotal < costtotal) return -1;

        for(int i =0 ; i < n ; i++){
            diff = curr + (gas[i%n]-cost[i%n]);
            if(diff<0){
                diff = 0;
                ans = i+1;
            } 
            curr = diff;
        }
        return ans;
    }
};

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minTill = INT_MAX;
        int profit = 0;
        for(int i : prices){
            if(i < minTill){
                minTill = i;
            }
            profit = max(profit , i - minTill);
        }
        return profit;
    }
};

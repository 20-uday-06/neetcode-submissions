class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin() , intervals.end());
        int n = intervals.size();
        int start = intervals[0][0];
        int end = intervals[0][1];

        int count = 0;

        for(int i = 1 ; i < n ; i++){
            if(intervals[i][0] < end){
                if(intervals[i][1] < end){
                    end = intervals[i][1];
                    start =intervals[i][0];
                }
                count++;
            }
            else end = intervals[i][1];
        }
        return count;
    }
};

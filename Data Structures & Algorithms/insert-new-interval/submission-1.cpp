class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        int n = intervals.size();
        int start = newInterval[0];
        int end = newInterval[1];

        while(i < n && intervals[i][1] < start){
            ans.push_back(intervals[i]);
            i++;
        }
        while(i < n && !(intervals[i][1] < start || intervals[i][0] > end)){
            end = max(intervals[i][1] , end);
            start= min(intervals[i][0] , start);
            i++;
        }
        ans.push_back({start ,end});
        while(i < intervals.size()){
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};

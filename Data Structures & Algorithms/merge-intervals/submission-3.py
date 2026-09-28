class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        intervals.sort()
        ans = []
        start = intervals[0][0]
        end = intervals[0][1]
        n = len(intervals)

        for i in range(1 , n):
            if intervals[i][0] <= end :
                start = min(start , intervals[i][0])
                end = max(end , intervals[i][1])
            else:
                ans.append([start , end])
                start = intervals[i][0]
                end= intervals[i][1]
        ans.append([start ,end])
        return ans
        
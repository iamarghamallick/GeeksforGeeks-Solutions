class Solution {
  public:
    vector<vector<int>> insertInterval(vector<vector<int>> &intervals,
                                       vector<int> &newInterval) {
        int n = intervals.size();
        int i = 0;
        while(i < n && intervals[i][0] <= newInterval[0])
            i++;
        intervals.insert(intervals.begin() + i, newInterval);
        
        vector<vector<int>> ans;
        n = intervals.size();
        ans.push_back(intervals[0]);
        i = 0;
        for(auto interval : intervals) {
            int currStart = ans[i][0];
            int currEnd = ans[i][1];
            
            int nextStart = interval[0];
            int nextEnd = interval[1];
            
            if(currEnd >= nextStart) {
                // overlapping, so update
                ans[i][0] = min(currStart, nextStart);
                ans[i][1] = max(currEnd, nextEnd);
            } else {
                // insert new non-overlapping interval
                ans.push_back(interval);
                i++;
            }
        }
        
        return ans;
    }
};
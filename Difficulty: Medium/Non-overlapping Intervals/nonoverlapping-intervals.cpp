//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minRemoval(vector<vector<int>> &intervals) {
        int count = 0;
  
        // Sort by minimum starting point
        sort(intervals.begin(), intervals.end());
    
        int end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
    
            // If the current starting point is less than
            // the previous interval's ending point
            // (ie. there is an overlap)
            if (intervals[i][0] < end) {
              
                // Increase count and remove the interval
                // with the higher ending point
                  count++;
                end = min(intervals[i][1], end);
            }
              
              // Incase of no overlapping, this interval is 
              // not removed and 'end' will be updated
            else
                end = intervals[i][1];
        }
    
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<vector<int>> intervals(N, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> intervals[i][0] >> intervals[i][1];
        }
        Solution obj;
        cout << obj.minRemoval(intervals) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
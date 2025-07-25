class Solution {
  public:
    int maxCircularSum(vector<int> &arr) {
        int n = arr.size();
        int total = 0;
        int minSum = INT_MAX, minEnding = 0;
        int maxSum = INT_MIN, maxEnding = 0;
        
        for(int i=0; i<n; i++) {
            total += arr[i];
            
            minEnding = min(minEnding + arr[i], arr[i]);
            minSum = min(minSum, minEnding);
            
            maxEnding = max(maxEnding + arr[i], arr[i]);
            maxSum = max(maxSum, maxEnding);
        }
        
        if(total == minSum) return maxSum;
        
        return max(maxSum, total - minSum);
    }
};
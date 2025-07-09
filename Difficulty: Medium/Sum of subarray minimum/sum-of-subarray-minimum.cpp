class Solution {
  public:
    int sumSubMins(vector<int> &arr) {
        int n = arr.size();
        vector<int> dp(n, 0);
        vector<int> right(n);
        vector<int> stack;
    
        // Initialize right[] to self indices
        for (int i = 0; i < n; i++) right[i] = i;
    
        // Find index of next 
        // smaller element on the right
        for (int i = 0; i < n; i++) {
            while (!stack.empty() && arr[i] < arr[stack.back()]) {
                right[stack.back()] = i;
                stack.pop_back();
            }
            stack.push_back(i);
        }
    
        // Fill dp[] from right to left
        dp[n - 1] = arr[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            int r = right[i];
            if (r == i) {
                dp[i] = (n - i) * arr[i];
            } else {
                dp[i] = (r - i) * arr[i] + dp[r];
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
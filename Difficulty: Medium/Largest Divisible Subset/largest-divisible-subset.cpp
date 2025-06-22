class Solution {
  public:
    vector<int> largestSubset(vector<int>& arr) {
        int n = arr.size();
        vector<int> dp(n, 1), hash(n);
        int maxi = 1;

        sort(arr.begin(), arr.end());
        reverse(arr.begin(), arr.end());
        
        for(int i=0; i<n; i++) {
            hash[i] = i;
            for(int j=0; j<i; j++) {
                if(arr[j] % arr[i] == 0 &&
                   1 + dp[j] > dp[i]) {
                    dp[i] = dp[j] + 1;
                    hash[i] = j;
                }
            }
        }
        
        int ans = -1;
        int lastIndex = -1;
        
        for (int i = 0; i < n; i++) {
            if (dp[i] > ans) {
                ans = dp[i];
                lastIndex = i;
            }
        }
        
        vector<int> temp;
        temp.push_back(arr[lastIndex]);
        
        while(hash[lastIndex] != lastIndex) {
            lastIndex = hash[lastIndex];
            temp.push_back(arr[lastIndex]);
        }
        
        return temp;
    }
};
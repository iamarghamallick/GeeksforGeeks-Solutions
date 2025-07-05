class Solution {
  public:
    int maxSum(vector<int> &arr) {
        int ans = arr[0] + arr[1];
        
        for(int i=1; i<arr.size(); i++) {
            ans = max(ans, arr[i-1] + arr[i]);
        }
        
        return ans;
    }
};
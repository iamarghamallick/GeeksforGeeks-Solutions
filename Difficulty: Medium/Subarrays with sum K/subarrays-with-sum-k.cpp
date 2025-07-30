class Solution {
  public:
    int cntSubarrays(vector<int> &arr, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int preSum = 0, ans = 0;
        for(int i=0; i<arr.size(); i++) {
            preSum += arr[i];
            int remove = preSum - k;
            ans += map[remove];
            map[preSum]++;
        }
        
        return ans;
    }
};
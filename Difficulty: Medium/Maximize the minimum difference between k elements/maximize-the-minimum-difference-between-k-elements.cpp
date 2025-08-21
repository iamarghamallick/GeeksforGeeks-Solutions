class Solution {
  public:
    int maxMinDiff(vector<int>& arr, int k) {
        sort(arr.begin(), arr.end());
        int low = 0, high = 1e5;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int prev = arr[0], count = 1;
            for(int i=1; i<arr.size(); i++) {
                if(arr[i] - prev >= mid) {
                    prev = arr[i];
                    count++;
                }
            }
            if(count >= k) low = mid+1;
            else high = mid - 1;
        }
        
        return high;
    }
};

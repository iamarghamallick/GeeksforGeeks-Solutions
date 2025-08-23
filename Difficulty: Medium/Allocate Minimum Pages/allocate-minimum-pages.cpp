class Solution {
  public:
    int getMinK(vector<int> &arr, int mid) {
        int n = arr.size();
        int minK = 1, curr = 0;
        for(int i=0; i<n; i++) {
            if(curr + arr[i] <= mid) curr += arr[i];
            else {
                minK++;
                curr = arr[i];
            }
        }
        return minK;
    }
    
    int findPages(vector<int> &arr, int k) {
        if(arr.size() < k) return -1;
        
        int low = INT_MIN, high = 0;
        for(int num : arr) {
            low = max(low, num);
            high += num;
        }
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int minK = getMinK(arr, mid);
            if(minK > k) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};
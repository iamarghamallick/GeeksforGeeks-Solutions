class Solution {
  public:
    int getMinDays(vector<int> &arr, int mid, int k) {
        int n = arr.size();
        vector<bool> isBlooming(n, false);
        
        for(int i=0; i<n; i++)
            if(arr[i] <= mid)
                isBlooming[i] = true;
        
        int m = 0;
        int i = 0, curr = 0;
        while(i < n) {
            if(isBlooming[i]) curr++;
            else curr = 0;
            
            if(curr == k) {
                m++;
                curr = 0;
            }
            
            i++;
        }
        
        return m;
    }
  
    int minDaysBloom(vector<int>& arr, int k, int m) {
        int n = arr.size();
        
        if(n < m*k) return -1;
        
        int low = INT_MAX, high = INT_MIN;
        
        for(int  num : arr) {
            low = min(low, num);
            high = max(high, num);
        }
        
        while(low <= high) {
            int mid = (low + high) / 2;
            int bouquets = getMinDays(arr, mid, k);
            if(bouquets < m) low = mid + 1;
            else high = mid - 1;
        }
        
        return low;
    }
};
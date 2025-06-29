class Solution {
  public:
    bool isPossible(vector<int>& arr, int k, long long mid) {
        int count = 1;
        long long sum = 0;
        for (int num : arr) {
            if (sum + num <= mid) {
                sum += num;
            } else {
                count++;
                sum = num;
                if (count > k) return false;
            }
        }
        return true;
    }
    
      int splitArray(vector<int>& arr, int k) {
        long long low = *max_element(arr.begin(), arr.end());
        long long high = accumulate(arr.begin(), arr.end(), 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }
        return low;
       
        
    }
};
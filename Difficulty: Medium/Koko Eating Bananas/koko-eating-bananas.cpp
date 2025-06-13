class Solution {
  public:
    bool check(vector<int>& arr, int mid, int k) {
        int hours = 0;
        
        for (int i = 0; i < arr.size(); i++) {
            hours += arr[i] / mid;
          
            // 1 extra hour to eat the remainder 
            // number of bananas in this pile
            if (arr[i] % mid != 0) {
                hours++;
            }
        }
    
        // return true if required time is less than 
        // or equals to given hour, otherwise return false
        return hours <= k;
    }

    int kokoEat(vector<int>& arr, int k) {
        int lo = 1;
        
        // Maximum speed of eating is 
        // the maximum bananas in given piles
        int hi = *max_element(arr.begin(), arr.end());
        int res = hi;
    
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
    
            // Check if the mid(hours) is valid
            if (check(arr, mid, k) == true) {
                // If valid continue to search at
                // lower speed
                hi = mid - 1;
                  res = mid;
            } else {
                // If cant finish bananas in given
                // hours, then increase the speed
                lo = mid + 1;
            }
        }
      
        return res;
    }
};

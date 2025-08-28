class Solution {
  public:
    int maxOnes(vector<int>& arr, int k) {
        int n = arr.size();
        int start = 0, end = 0;
        int maxLen = 0;
        
        while(end < n) {
            if(arr[end] == 1) {
                maxLen = max(maxLen, end - start + 1);
                end++;
            } else { // if(arr[end] == 0)
                if(k > 0) { // flip
                    k--;
                    maxLen = max(maxLen, end - start + 1);
                    end++;
                } else { // flip oldest flipped 0 to 1, and continue
                    while(start <= end && arr[start] != 0)
                        start++;
                    
                    start++;
                    
                    maxLen = max(maxLen, end - start + 1);
                    end++;
                }
            }
        }
        
        return maxLen;
    }
};

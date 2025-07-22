class Solution {
  public:
    int missingNumber(vector<int> &arr) {
        int n = arr.size();
        int i = 0;
        
        while(i < n) {
            // if arr[i] is out of range 
            if(arr[i] <= 0 || arr[i] > n) i++;
            // if arr[i] is already at expected position
            else if(arr[i] - 1 == i) i++;
            // if a valid num is already placed at arr[i]-th index
            else if(arr[arr[i] - 1] == arr[i]) i++;
            // swap
            else
                swap(arr[i], arr[arr[i] - 1]);
        }
        
        int ans = n + 1;
        for(int i=0; i<n; i++) {
            if(arr[i]-1 != i) {
                ans = i+1;
                break;
            }
        }
        
        return ans;
    }
};
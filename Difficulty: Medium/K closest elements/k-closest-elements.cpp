class Solution {
  public:
    vector<int> printKClosest(vector<int> arr, int k, int x) {
        int n = arr.size();
        int left = 0, right = n - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(x == arr[mid]) {
                left = mid + 1;
                right = mid - 1;
                break;
            } else if(x > arr[mid]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        swap(left, right);
        
        vector<int> ans;
        
        while(k--) {
            if(left < 0) {
                ans.push_back(arr[right++]);
            } else if(right >= n) {
                ans.push_back(arr[left--]);
            } else if(abs(arr[left] - x) == abs(arr[right] - x)) {
                ans.push_back(arr[right++]);
            } else if(abs(arr[left] - x) < abs(arr[right] - x)) {
                ans.push_back(arr[left--]);
            } else {
                ans.push_back(arr[right++]);
            }
        }
        
        return ans;
    }
};
class Solution {
    public int findKRotation(int arr[]) {
        int n = arr.length;
        int left = 0, right = arr.length - 1;
        int ans = 0;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            if(arr[mid] == 1)
                return mid;
            if(arr[mid] > arr[n-1]) {
                left = mid + 1;
            } else {
                ans = mid;
                right = mid - 1;
            }
        }
        
        return ans;
    }
}
class Solution {
    public int kthMissing(int[] arr, int k) {
        int n = arr.length;
        int start = 0;
        int end = n-1;
        int index = n-1;
        
        while(start <= end) {
            int mid = start + ((end-start)/2);
            int miss = arr[mid] - (mid + 1); // missing element from that index.
            if(miss < k)
                start = mid+1;
            else {
                index = mid;
                end = mid-1;
            }
        }
        
        int miss = arr[index] - (index+1);
        if(miss >= k) {
           int a = miss-k;
           return arr[index]-(a+1);
        } else {
            k -= miss;
            return arr[index]+k;
        }
    }
}
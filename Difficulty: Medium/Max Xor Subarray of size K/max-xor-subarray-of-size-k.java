class Solution {
    public int maxSubarrayXOR(int[] arr, int k) {
        int xor = 0;
        for(int i=0; i<k; i++)
            xor ^= arr[i];
            
        int ans = xor;
        for(int i=k; i<arr.length; i++) {
            xor ^= arr[i];
            xor ^= arr[i-k];
            ans = Math.max(ans, xor);
        }
        
        return ans;
    }
}

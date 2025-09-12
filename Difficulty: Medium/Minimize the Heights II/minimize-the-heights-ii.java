class Solution {
    public int getMinDiff(int[] arr, int k) {
        int n = arr.length;
        Arrays.sort(arr);
        int minHeight = arr[0];
        int maxHeight = arr[n-1];
        int ans = maxHeight - minHeight;
        
        for(int i=1; i<n; i++) {
            if (arr[i] - k < 0)
                continue;
            minHeight = Math.min(arr[0] + k, arr[i] - k);
            maxHeight = Math.max(arr[i-1] + k, arr[n-1] - k);
            ans = Math.min(ans, maxHeight - minHeight);
        }
        
        return ans;
    }
}

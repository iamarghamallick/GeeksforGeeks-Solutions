class Solution {
    public int maxPathSum(int[] a, int[] b) {
        int n = a.length;
        int m = b.length;
        int i = 0;
        int j = 0;
        
        int ans = 0;
        int left = 0;
        int right = 0;
        
        while(i < n && j < m) {
            if(a[i] == b[j]) {
                ans += a[i] + Math.max(left, right);
                left = 0;
                right = 0;
                i++;
                j++;
            } else if(a[i] < b[j]) {
                left += a[i];
                i++;
            } else {
                right += b[j];
                j++;
            }
        }
        
        while(i < n) {
            left += a[i];
            i++;
        }
        
        while(j < m) {
            right += b[j];
            j++;
        }
        
        return ans + Math.max(left, right);
    }
}
class Solution {
    public int maxSumWithK(int[] a, int k) {
        int n = a.length, sum = 0, mx = 0, prev = 0;
        int i = 0, j = 0;
        
        while(i < k)
            sum += a[i++];
        
        mx = sum;
        
        while(i < n) {
            sum += a[i++];
            prev += a[j++];
            mx = Math.max(mx, sum);
            
            if(prev < 0) {
                sum -= prev;
                prev = 0;
                mx = Math.max(mx, sum);
            }
        }
        
        return mx;
    }
}
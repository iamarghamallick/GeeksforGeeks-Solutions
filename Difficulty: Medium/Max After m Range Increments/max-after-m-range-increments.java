class Solution {
    public int findMax(int n, int[] a, int[] b, int[] k) {
        int[] prefix = new int[n];
        
        for(int i=0; i<a.length; i++) {
            int first = a[i];
            int second = b[i];
            
            prefix[first] += k[i];
            if(second + 1 < n){
                prefix[second + 1] -= k[i]; 
            }
        }
        
        for(int i=1; i<n; i++) {
            prefix[i] += prefix[i-1];
        }
        
        int max = Integer.MIN_VALUE;
            
        for(int i=0; i<n; i++) {
            if(max < prefix[i]) {
                max = prefix[i];
            }
        }
        
        return max;
    }
}

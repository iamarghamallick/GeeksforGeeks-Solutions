class Solution {
    public static int minCost(int n, int m, int[] x, int[] y) {
        int ans = 0;
        
        Arrays.sort(x);
        Arrays.sort(y);
        
        int rowsPart = 1;
        int colsPart = 1;
        
        int i = m-2;
        int j = n-2;
        
        while(i >= 0 && j >= 0) {
            if(x[i] > y[j]) {
                ans += x[i] * rowsPart;
                colsPart++;
                i--;
            } else {
                ans += y[j] * colsPart;
                rowsPart++;
                j--;
            }
        }
        
        while(i >= 0) {
            ans += x[i] * rowsPart;
            colsPart++;
            i--;
        }
        
        while(j >= 0) {
            ans += y[j] * colsPart;
            rowsPart++;
            j--;
        }
        
        return ans;
    }
}

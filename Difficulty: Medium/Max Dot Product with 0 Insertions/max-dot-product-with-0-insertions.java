class Solution {
    public int maxDotProduct(int[] a, int[] b) {
        int[][] dp = new int[a.length+1][a.length+1];
        for(int[] r: dp) {
            Arrays.fill(r, -1);
        }
        return solve(a, b, 0, 0, dp);
    }
    
    static int solve(int[] a, int[] b, int i, int j, int[][] dp) {
        if(j == b.length) return 0;
        if(i == a.length) return Integer.MIN_VALUE;
        if(dp[i][j] != -1) return dp[i][j];
        if(a.length - i < b.length - j) return Integer.MIN_VALUE;
        
        int take = a[i]*b[j] + solve(a, b, i+1, j+1, dp);
        int skip = solve(a, b, i+1, j, dp);
        
        return dp[i][j] = Math.max(take, skip);
    }
}
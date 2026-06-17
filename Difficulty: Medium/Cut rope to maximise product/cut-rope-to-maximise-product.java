class Solution {
    int len;
    
    public int maxProduct(int n) {
        len = n;
        int[][] dp = new int[n+1][n+1];
        
        for(int i=0; i<=n; i++) 
            for(int j=0; j<=n; j++)
                dp[i][j] = -1;
                
        return solve(1, n, dp);
    }
    
    private int solve(int i, int rem, int[][] dp) {
        if(rem == i) {
            if(rem == len) return 0;
            else return rem;
        }
        
        if(i > rem) return 0;
        if(dp[i][rem] != -1) return dp[i][rem];
        
        return dp[i][rem] = Math.max(i * solve(i, rem - i, dp), 
                                    solve(i+1, rem, dp));
    }
}
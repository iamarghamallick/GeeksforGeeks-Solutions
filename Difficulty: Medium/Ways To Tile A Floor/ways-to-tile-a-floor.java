class Solution {
    public int numberOfWays(int n) {
        // if(n < 0) return 0;
        // if(n == 0) return 1;
        // return numberOfWays(n-1) + numberOfWays(n-2);
        
        int[] dp = new int[n+1];
        return solve(n, dp);
    }
    
    private int solve(int n, int[] dp) {
        if(n < 0) return 0;
        if(n == 0) return 1;
        if(dp[n] > 0) return dp[n];
        return dp[n] = solve(n-1, dp) + solve(n-2, dp);
    }
};
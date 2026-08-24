class Solution {
    public int prefixStrings(int n) {
        int[] dp = new int[n+1];
        dp[0] = 1; dp[1] = 1;
        
        for(int i=2; i<=n; i++) {
            long res = 0;
            
            for(int j=0; j<i; j++) {
                res = (res + 1L * dp[j] * dp[i - j - 1]) % 1000000007;
            }
            
            dp[i] = (int) res;
        }
        
        return dp[n];
    }
}
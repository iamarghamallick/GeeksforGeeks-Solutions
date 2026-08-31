class Solution {
    public int minCost(int n, int i, int d, int c) {
        int[] dp = new int[n + 1];

        dp[0] = 0;
        dp[1] = i;

        for (int len = 2; len <= n; len++) {

            // Insert one character
            dp[len] = i + dp[len - 1];

            // Copy
            if (len % 2 == 0) {
                dp[len] = Math.min(
                    dp[len],
                    c + dp[len / 2]
                );
            } else {
                // Build len + 1, copy, then delete one
                dp[len] = Math.min(
                    dp[len],
                    c + d + dp[(len + 1) / 2]
                );
            }
        }

        return dp[n];
    }
}

// class Solution {
// 	public int minCost(int n, int i, int d, int c) {
// 		int[] dp = new int[n + 1];
		
// 		Arrays.fill(dp, -1);
		
// 		return solve(n, i, d, c, dp);
// 	}
	
// 	private int solve(int n, int i, int d, int c, int[] dp) {
// 		if (n == 0) {
// 			return 0;
// 		}
		
// 		if (n == 1) {
// 			return i;
// 		}
		
// 		if (dp[n] != -1) {
// 			return dp[n];
// 		}
		
// 		// insert
// 		int ans = i + solve(n - 1, i, d, c, dp);
		
// 		if (n % 2 == 0) {
// 			// copy n / 2 chars
// 			ans = Math.min(ans, c + solve(n/2, i, d, c, dp));
// 		} else {
// 			// copy (n+1) / 2 chars and delete 1
// 			ans = Math.min(ans, c + d + solve((n + 1)/2, i, d, c, dp));
// 		}
		
// 		return dp[n] = ans;
// 	}
// }

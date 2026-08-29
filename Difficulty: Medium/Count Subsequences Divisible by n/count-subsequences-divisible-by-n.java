class Solution {

    static final int MOD = 1_000_000_007;

    public int countSubsequences(String s, int n) {

        // dp[r] = number of non-empty subsequences
        // having remainder r
        int[] dp = new int[n];

        for (int i = 0; i < s.length(); i++) {

            int digit = s.charAt(i) - '0';

            // Update backwards using a copy of the previous state
            int[] next = dp.clone();

            // Start a new subsequence with just this digit
            int rem = digit % n;
            next[rem] = (next[rem] + 1) % MOD;

            // Append current digit to every existing subsequence
            for (int r = 0; r < n; r++) {

                int newRem = (r * 10 + digit) % n;

                next[newRem] = (next[newRem] + dp[r]) % MOD;
            }

            dp = next;
        }

        return dp[0];
    }
}

// class Solution {
	
// 	static final int MOD = 1_000_000_007;
	
// 	public int countSubsequences(String s, int n) {
// 		int[][] dp = new int[s.length()][n];
		
// 		for (int i = 0; i < s.length(); i++) {
// 			Arrays.fill(dp[i], -1);
// 		}
		
// 		return solve(0, 0, s, n, dp) - 1; // substract ""
// 	}
	
// 	private int solve(int i, int rem, String s, int n, int[][] dp) {
// 		if (i == s.length()) {
// 			return rem == 0 ? 1 : 0;
// 		}
		
// 		if (dp[i][rem] != -1) {
// 			return dp[i][rem];
// 		}
		
// 		// Exclude current digit
// 		int exclude = solve(i + 1, rem, s, n, dp);
		
// 		// Include current digit
// 		int digit = s.charAt(i) - '0';
// 		int newRem = (rem * 10 + digit) % n;
		
// 		int include = solve(i + 1, newRem, s, n, dp);
		
// 		return dp[i][rem] = (exclude + include) % MOD;
// 	}
// }

// class Solution {

// 	int MOD = 1000000007;

// 	public int countSubsequences(String s, int n) {
// 		int[][][] dp = new int[s.length()][n][2];

// 		for (int i = 0; i<s.length(); i++) {
// 			for (int j = 0; j<n; j++) {
// 				for (int k = 0; k<2; k++) {
// 					dp[i][j][k] = -1;
// 				}
// 			}
// 		}

// 		return solve(0, 0, 0, s, n, dp); // (s[i], rem, started, s, n)
// 	}

// 	private int solve(int i, int rem, int started, String s, int n, int[][][] dp) {
// 		if (i == s.length()) {
// 			if (started == 1 && rem == 0) {
// 				return 1;
// 			}

// 			return 0;
// 		}

// 		if (dp[i][rem][started] != -1) {
// 			return dp[i][rem][started];
// 		}

// 		int exclude = solve(i + 1, rem, started, s, n, dp);

// 		int newRem = (rem * 10 + (s.charAt(i) - '0')) % n;
// 		int include = solve(i + 1, newRem, 1, s, n, dp);

// 		return dp[i][rem][started] = (exclude + include) % MOD;
// 	}
// }

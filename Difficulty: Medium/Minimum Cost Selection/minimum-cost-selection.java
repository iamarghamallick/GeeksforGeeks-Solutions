class Solution {
	public int minCost(int[][] mat) {
		int n = mat.length;
		
		int[][] dp = new int[n][3];
		
		for (int[] row : dp) {
			Arrays.fill(row, -1);
		}
		
		int ans = Integer.MAX_VALUE;
		
		for (int choice = 0; choice<3; choice++) {
			ans = Math.min(ans,
			mat[0][choice] + solve(1, choice, mat, dp));
		}
		
		return ans;
	}
	
	private int solve(int i, int prev, int[][] mat, int[][] dp) {
		int n = mat.length;
		
		if (i == n) {
			return 0;
		}
		
		if (dp[i][prev] != -1) {
			return dp[i][prev];
		}
		
		int ans = Integer.MAX_VALUE;
		
		for (int choice = 0; choice<3; choice++) {
			if (choice != prev) {
				ans = Math.min(ans,
				mat[i][choice] + solve(i + 1, choice, mat, dp));
			}
		}
		
		return dp[i][prev] = ans;
	}
}

class Solution {
	public int findMinCost(String s1, String s2, int costS1, int costS2) {
		int n1 = s1.length();
		int n2 = s2.length();
		
		int[][] dp = new int[n1][n2];
		
		for (int i = 0; i<n1; i++) {
			Arrays.fill(dp[i], -1);
		}
		
		int minLen = lcs(0, 0, s1, s2, dp);
		
		return costS1 * (n1 - minLen) + costS2 * (n2 - minLen);
	}
	
	private int lcs(int i, int j, String s1, String s2, int[][] dp) {
		int n1 = s1.length();
		int n2 = s2.length();
		
		if (i == n1 || j == n2) {
			return 0;
		}
		
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		
		if (s1.charAt(i) == s2.charAt(j)) {
			return dp[i][j] = 1 + lcs(i + 1, j + 1, s1, s2, dp);
		}
		
		return dp[i][j] = Math.max(lcs(i + 1, j, s1, s2, dp), lcs(i, j + 1, s1, s2, dp));
	}
}

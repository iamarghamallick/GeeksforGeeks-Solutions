class Solution {
	public int getMaxWeight(String s) {
		int n = s.length();
		
		int[] dp = new int[n];
		
		Arrays.fill(dp, -1);
		
		return solve(0, s, dp);
	}
	
	private int solve(int i, String s, int[] dp) {
		int n = s.length();
		
		if (i >= n) {
			return 0;
		}
		
		if (dp[i] != -1) {
			return dp[i];
		}
		
		int takeSingle = 1 + solve(i + 1, s, dp);
		int takePair = 0;
		
		if (i < n - 1) {
			if (s.charAt(i) != s.charAt(i + 1)) {
				takePair = 4 + solve(i + 2, s, dp);
			} else {
				takePair = 3 + solve(i + 2, s, dp);
			}
		}
		
		return dp[i] = Math.max(takeSingle, takePair);
	}
}

class Solution {
	public int minimumCost(int x, int s, int m, int l, int cs, int cm, int cl) {
		int[] dp = new int[x + l];
		
		Arrays.fill(dp, -1);
		
		return solve(0, x, s, m, l, cs, cm, cl, dp);
	}
	
	private int solve(int i, int x, int s, int m, int l, int cs, int cm, int cl, int[] dp) {
		if (i >= x) {
			return 0;
		}
		
		if (dp[i] != -1) {
			return dp[i];
		}
		
		int takeS = cs + solve(i + s, x, s, m, l, cs, cm, cl, dp);
		int takeM = cm + solve(i + m, x, s, m, l, cs, cm, cl, dp);
		int takeL = cl + solve(i + l, x, s, m, l, cs, cm, cl, dp);
		
		return dp[i] = Math.min(takeS, Math.min(takeM, takeL));
	}
}

class Solution {
	public int ways(int x, int y) {
		int[][] dp = new int[x + 1][y + 1];
		
		for (int[] row: dp) {
			Arrays.fill(row, -1);
		}
		
		return solve(x, y, dp);
	}
	
	private int solve(int x, int y, int[][] dp) {
		if (x == 0 || y == 0)
			return 1;
		
		if (dp[x][y] != -1)
			return dp[x][y];
		
		return dp[x][y] = (solve(x - 1, y, dp) + solve(x, y - 1, dp))
		% 1000000007;
	}
}

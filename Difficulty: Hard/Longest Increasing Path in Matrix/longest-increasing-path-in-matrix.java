class Solution {
	public int longIncPath(int[][] matrix, int n, int m) {
		int ans = 0;
		
		int[][] dp = new int[n][m];
		
		for (int i = 0; i<n; i++) {
			Arrays.fill(dp[i], -1);
		}
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				ans = Math.max(ans, solve(i, j, matrix, n, m, dp));
			}
		}
		
		return ans;
	}
	
	private int solve(int i, int j, int[][] matrix, int n, int m, int[][] dp) {
		int ans = 1;
		
		int[][] dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
		
		if (dp[i][j] != -1) {
			return dp[i][j];
		}
		
		for (int[] dir: dirs) {
			int ni = i + dir[0];
			int nj = j + dir[1];
			
			if (0 <= ni && ni < n &&
			0 <= nj && nj < m &&
			matrix[ni][nj] > matrix[i][j]) {
				ans = Math.max(ans, 1 + solve(ni, nj, matrix, n, m, dp));
			}
		}
		
		return dp[i][j] = ans;
	}
}

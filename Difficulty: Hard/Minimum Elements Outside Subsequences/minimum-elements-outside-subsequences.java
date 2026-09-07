class Solution {
	
	int[][][] dp;
	
	public int minCount(int[] arr) {
		int n = arr.length;
		dp = new int[n][n + 1][n + 1];
		
		for (int[][] i: dp) {
			for (int[] j: i) {
				Arrays.fill(j, -1);
			}
		}
		
		return n - find(0, -1, -1, arr);
	}
	
	private int find(int i, int inc, int dec, int[] arr) {
		if (i == arr.length) {
			return 0;
		}
		
		if (dp[i][inc + 1][dec + 1] != -1) {
			return dp[i][inc + 1][dec + 1];
		}
		
		int ans = find(i + 1, inc, dec, arr);
		
		if (inc == -1 || arr[i]>arr[inc]) {
			ans = Math.max(ans, 1 + find(i + 1, i, dec, arr));
		}
		
		if (dec == -1 || arr[i]<arr[dec]) {
			ans = Math.max(ans, 1 + find(i + 1, inc, i, arr));
		}
		
		return dp[i][inc + 1][dec + 1] = ans;
	}
}

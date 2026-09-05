class Solution {
	public int longestSubseq(int[] arr) {
		Map<Integer, Integer> dp = new HashMap<>();
		
		int ans = 0;
		
		for (int x: arr) {
			int prev1 = dp.getOrDefault(x - 1, 0);
			int prev2 = dp.getOrDefault(x + 1, 0);
			
			int curr = Math.max(prev1, prev2) + 1;
			
			dp.put(x, Math.max(dp.getOrDefault(x, 0), curr));
			
			ans = Math.max(ans, dp.get(x));
		}
		
		return ans;
	}
}

// class Solution {
// 	public int longestSubseq(int[] arr) {
// 		int n = arr.length;

// 		int[][] dp = new int[n + 1][n];

// 		for (int[] row : dp) {
// 			Arrays.fill(row, -1);
// 		}

// 		return solve(-1, 0, arr, dp);
// 	}

// 	private int solve(int prev, int curr, int[] arr, int[][] dp) {
// 		if (curr == arr.length) {
// 			return 0;
// 		}

// 		if (dp[prev + 1][curr] != -1) {
// 			return dp[prev + 1][curr];
// 		}

// 		int take = 0;

// 		if (prev == -1 || Math.abs(arr[prev] - arr[curr]) == 1) {
// 			take = 1 + solve(curr, curr + 1, arr, dp);
// 		}

// 		int notTake = solve(prev, curr + 1, arr, dp);

// 		return dp[prev + 1][curr] = Math.max(take, notTake);
// 	}
// }

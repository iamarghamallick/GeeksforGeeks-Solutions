class Solution {
	public int maxPackages(int[] arr, int totalTime) {
		int n = arr.length;
		
		int ans = 0;
		
		for (int i = 0; i < Math.min(n, totalTime); i++) {
			ans += arr[i];
		}
		
		int res = ans;
		
		for (int start = 0, i = Math.min(n, totalTime); i<n; i++, start++) {
			res = res - arr[start] + arr[i];
			ans = Math.max(ans, res);
		}
		
		return ans;
	}
}

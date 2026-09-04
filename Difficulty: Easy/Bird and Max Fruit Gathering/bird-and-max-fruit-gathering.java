class Solution {
	public int maxFruits(ArrayList<Integer> arr, int m) {
		int n = arr.size();
		int sum = 0;
		
		for (int i = 0; i<m; i++) {
			sum += arr.get(i);
		}
		
		int ans = sum;
		
		for (int i = m; i<n + m; i++) {
			sum -= arr.get(i - m);
			sum += arr.get(i%n);
			ans = Math.max(ans, sum);
		}
		
		return ans;
	}
}

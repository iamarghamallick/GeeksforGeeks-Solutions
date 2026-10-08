class Solution {
	public int maxFrequency(int[] arr, int k) {
		Arrays.sort(arr);
		int sum = 0;
		int start = 0;
		int end = 0;
		int ans = 0;
		
		while (end < arr.length) {
			int target = arr[end];
			sum += arr[end];
			int required = (target * (end - start + 1)) - sum;
			
			if (required <= k) {
				ans = Math.max(ans, end - start + 1);
			} else {
				sum -= arr[start];
				start++;
			}
			
			end++;
		}
		
		return ans;
	}
}

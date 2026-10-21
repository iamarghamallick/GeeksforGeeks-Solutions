class Solution {
	public int minSubarraySum(int[] arr) {
		int curMin = Integer.MAX_VALUE;
		int ans = Integer.MAX_VALUE;
		
		for (int i = 0; i < arr.length; i++) {
			if (curMin > 0) {
				curMin = arr[i];
			} else {
				curMin += arr[i];
			}
			
			ans = Math.min(ans, curMin);
		}
		
		return ans;
	}
}

class Solution {
	public int smallestSubWithSum(int[] arr, int x) {
		int n = arr.length;
		int minLen = Integer.MAX_VALUE;
		int sum = 0;
		int i = 0;
		
		for (int j = 0; j<n; j++) {
			sum += arr[j];
			while (i <= j && sum > x) {
				minLen = Math.min(minLen, j - i + 1);
				sum -= arr[i];
				i++;
			}
		}
		
		return minLen == Integer.MAX_VALUE ? 0 : minLen;
	}
}

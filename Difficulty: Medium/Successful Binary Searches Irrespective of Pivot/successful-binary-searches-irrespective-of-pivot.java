class Solution {
	public int countAlwaysFound(int[] arr) {
		int n = arr.length;
		int[] maxLeft = new int[n];
		int[] minRight = new int[n];
		
		maxLeft[0] = arr[0];
		minRight[n - 1] = arr[n - 1];
		
		for (int i = 1; i<n; i++) {
			maxLeft[i] = Math.max(maxLeft[i - 1], arr[i]);
			minRight[n - i-1] = Math.min(minRight[n - i], arr[n - i-1]);
		}
		
		int count = 0;
		
		for (int i = 0; i<n; i++) {
			if (arr[i] == maxLeft[i] && arr[i] == minRight[i]) {
				count++;
			}
		}
		
		return count;
	}
}

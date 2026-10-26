class Solution {
	public int minDiff(int k, int[] arr) {
		int n = arr.length;
		
		int[] leftMin = new int[n];
		int[] leftMax = new int[n];
		int[] rightMin = new int[n];
		int[] rightMax = new int[n];
		
		leftMin[0] = arr[0];
		leftMax[0] = arr[0];
		rightMin[n - 1] = arr[n - 1];
		rightMax[n - 1] = arr[n - 1];
		
		for (int i = 1; i<n; i++) {
			leftMin[i] = Math.min(leftMin[i - 1], arr[i]);
			leftMax[i] = Math.max(leftMax[i - 1], arr[i]);
			
			rightMin[n - 1-i] = Math.min(rightMin[n - i], arr[n - 1-i]);
			rightMax[n - 1-i] = Math.max(rightMax[n - i], arr[n - 1-i]);
		}
		
		int ans = Integer.MAX_VALUE;
		
		for (int i = k - 1; i<n; i++) {
			int currMin, currMax;
			
			if (i - k < 0) {
				// left most k elements
				currMin = rightMin[i + 1];
				currMax = rightMax[i + 1];
			} else if (i == n - 1) {
				// right most k elements
				currMin = leftMin[i - k];
				currMax = leftMax[i - k];
			} else {
				currMin = Math.min(leftMin[i - k], rightMin[i + 1]);
				currMax = Math.max(leftMax[i - k], rightMax[i + 1]);
			}
			
			ans = Math.min(ans, Math.abs(currMax - currMin));
		}
		
		return ans;
	}
}

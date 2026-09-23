class Solution {
	public int formPyramid(int[] arr) {
		int n = arr.length;
		int totalHeight = 0;
		
		// Calculate the total height of all stones.
		for (int i = 0; i < n; i++)
			totalHeight += arr[i];
		
		// For arrays of size 1 or 2, the only possible
		// pyramid has height 1, so the remaining stones
		// must be reduced to 0.
		if (n <= 2)
			return totalHeight - 1;
		
		int[] left = new int[n];
		int[] right = new int[n];
		
		// left[i] = Maximum possible pyramid height at
		// index i considering only the left side.
		left[0] = 1;
		for (int i = 1; i < n; i++)
			left[i] = Math.min(left[i - 1] + 1, arr[i]);
		
		// right[i] = Maximum possible pyramid height at
		// index i considering only the right side.
		right[n - 1] = 1;
		for (int i = n - 2; i >= 0; i--)
			right[i] = Math.min(right[i + 1] + 1, arr[i]);
		
		int minCost = Integer.MAX_VALUE;
		
		// Try every index as the peak of the pyramid.
		for (int i = 0; i < n; i++) {
			
			// The peak height is limited by both the left
			// and right constraints.
			int peakHeight = Math.min(left[i], right[i]);
			
			// A pyramid of height h has a total sum of h².
			int pyramidSum = peakHeight * peakHeight;
			
			// Cost = Original total height - Height of the
			// constructed pyramid.
			minCost = Math.min(minCost,
			totalHeight - pyramidSum);
		}
		
		return minCost;
	}
};

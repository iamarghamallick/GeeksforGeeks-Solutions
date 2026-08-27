class Solution {
	public int maxArea(int[][] mat) {
		int n = mat.length;
		int m = mat[0].length;
		
		int[] height = new int[m];
		int maxArea = 0;
		
		for (int i = 0; i < n; i++) {
			
			// Build histogram heights for this row
			for (int j = 0; j < m; j++) {
				if (mat[i][j] == 1) {
					height[j]++;
				} else {
					height[j] = 0;
				}
			}
			
			// Column swaps allow us to arrange heights in any order.
			// Sort heights in descending order.
			int[] sorted = height.clone();
			Arrays.sort(sorted);
			
			// Use the largest k heights to make a rectangle.
			for (int k = 1; k <= m; k++) {
				int h = sorted[m - k];
				int area = h * k;
				maxArea = Math.max(maxArea, area);
			}
		}
		
		return maxArea;
	}
}

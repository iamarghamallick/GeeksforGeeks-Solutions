class Solution {
	public int largestSubsquare(char mat[][]) {
		int n = mat.length;
		
		// Matrices to store count of 'X' to the right
		// and bottom of cells.
		int[][] right = new int[n][n];
		int[][] down = new int[n][n];
		
		// Fill the right and down matrices
		for (int i = n - 1; i >= 0; i--) {
			for (int j = n - 1; j >= 0; j--) {
				if (mat[i][j] == 'X') {
					right[i][j] = (j == n - 1)
					? 1
					: right[i][j + 1] + 1;
					down[i][j] = (i == n - 1)
					? 1
					: down[i + 1][j] + 1;
				}
			}
		}
		
		int maxSize = 0;
		
		// Check each cell as the top-left corner of the
		// square
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				
				// Calculate the maximum possible side
				// length for the square starting at (i, j)
				int maxSide
				= Math.min(right[i][j], down[i][j]);
				
				// Iterate from the maximum side length down
				// to 1
				for (int side = maxSide; side > 0; side--) {
					
					// Check if the square of length
					// 'side' has valid borders
					if (right[i + side - 1][j] >= side
					 && down[i][j + side - 1] >= side) {
						maxSize = Math.max(maxSize, side);
						break;
					}
				}
			}
		}
		
		return maxSize;
	}
};

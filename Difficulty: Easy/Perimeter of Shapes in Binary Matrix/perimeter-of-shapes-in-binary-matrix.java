class Solution {
	static int findPerimeter(int[][] mat) {
		int ans = 0;
		
		for (int i = 0; i<mat.length; i++) {
			for (int j = 0; j<mat[0].length; j++) {
				ans += mat[i][j] == 0 ? 0 : perimeter(i, j, mat);
			}
		}
		
		return ans;
	}
	
	private static int perimeter(int i, int j, int[][] mat) {
		int res = 4;
		
		int n = mat.length;
		int m = mat[0].length;
		
		int[][] dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
		
		for (int[] dir: dirs) {
			int nI = i + dir[0];
			int nJ = j + dir[1];
			
			if (0 <= nI && nI < n && 0 <= nJ && nJ < m && mat[nI][nJ] == 1) {
				res--;
			}
		}
		
		return res;
	}
}

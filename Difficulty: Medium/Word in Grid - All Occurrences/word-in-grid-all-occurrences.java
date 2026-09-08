class Solution {
	public ArrayList<ArrayList<Integer>> searchWord(char[][] mat, String word) {
		int n = mat.length;
		int m = mat[0].length;
		int len = word.length();
		
		int[][] dirs = new int[][] {
			{-1, 0}, // up
			{1, 0}, // down
			{0, 1}, // right
			{0, -1}, // left
			{-1, -1}, // left up
			{1, 1}, // right down
			{-1, 1}, // right up
			{1, -1}, // left down
		};
		
		ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				for (int[] dir: dirs) {
					
					ArrayList<Integer> currStart = new ArrayList<>(List.of(i, j));
					
					int k;
					int currI = i;
					int currJ = j;
					
					for (k = 0; k<len; k++) {
						
						if (currI >= n || currI < 0 || currJ >= m || currJ < 0) {
							break;
						}
						
						if (mat[currI][currJ] != word.charAt(k)) {
							break;
						}
						
						currI += dir[0];
						currJ += dir[1];
					}
					
					if (k == len) {
						ans.add(currStart);
						break;
					}
				}
			}
		}
		
		return ans;
	}
};

class Solution {
	int shortestPath(int[][] mat) {
		int n = mat.length;
		int m = mat[0].length;
		
		boolean[][] visited = new boolean[n][m];
		Queue<int[]> q = new LinkedList<>();
		
		int[] dx = new int[] {-1, 1, 0, 0};
		int[] dy = new int[] {0, 0, -1, 1};
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (mat[i][j] == 0) {
					visited[i][j] = true;
					
					for (int k = 0; k<4; k++) {
						int ni = i + dx[k];
						int nj = j + dy[k];
						
						if (0 <= ni && ni < n && 0 <= nj && nj < m) {
							visited[ni][nj] = true;
						}
					}
				}
			}
		}
		
		for (int i = 0; i<n; i++) {
			if (!visited[i][0]) {
				q.offer(new int[] {1, i, 0});
				visited[i][0] = true;
			}
		}
		
		int ans = Integer.MAX_VALUE;
		
		while (!q.isEmpty()) {
			int[] front = q.poll();
			int dist = front[0];
			int i = front[1];
			int j = front[2];
			
			if (j == m - 1) {
				ans = Math.min(ans, dist);
			}
			
			for (int k = 0; k<4; k++) {
				int ni = i + dx[k];
				int nj = j + dy[k];
				
				if (0 <= ni && ni < n && 0 <= nj && nj < m && !visited[ni][nj]) {
					q.offer(new int[] {dist + 1, ni, nj});
					visited[ni][nj] = true;
				}
			}
		}
		
		return ans == Integer.MAX_VALUE ? -1 : ans;
	}
}

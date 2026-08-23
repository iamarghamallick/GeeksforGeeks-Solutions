class Solution {
	public int numberOfCells(int r, int c, int u, int d, char[][] mat) {
		int n = mat.length;
		int m = mat[0].length;
		
		if (mat[r][c] == '#') {
			return 0;
		}
		
		PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
			if (a[0] != b[0])
				return Integer.compare(a[0], b[0]);
			
			return Integer.compare(a[1], b[1]);
		});
		
		boolean[][] visited = new boolean[n][m];
		
		pq.offer(new int[] { 0, 0, r, c });
		visited[r][c] = true;
		
		while (!pq.isEmpty()) {
			
			int[] current = pq.poll();
			
			int upUsed = current[0];
			int downUsed = current[1];
			int x = current[2];
			int y = current[3];
			
			// Move Up.
			if (isValid(x - 1, y, n, m)
				 && !visited[x - 1][y]
			 && mat[x - 1][y] == '.' && upUsed < u) {
				
				visited[x - 1][y] = true;
				
				pq.offer(new int[] { upUsed + 1, downUsed,
				x - 1, y });
			}
			
			// Move Down.
			if (isValid(x + 1, y, n, m)
				 && !visited[x + 1][y]
			 && mat[x + 1][y] == '.' && downUsed < d) {
				
				visited[x + 1][y] = true;
				
				pq.offer(new int[] { upUsed, downUsed + 1,
				x + 1, y });
			}
			
			// Move Left.
			if (isValid(x, y - 1, n, m)
				 && !visited[x][y - 1]
			 && mat[x][y - 1] == '.') {
				
				visited[x][y - 1] = true;
				
				pq.offer(new int[] { upUsed, downUsed, x,
				y - 1 });
			}
			
			// Move Right.
			if (isValid(x, y + 1, n, m)
				 && !visited[x][y + 1]
			 && mat[x][y + 1] == '.') {
				
				visited[x][y + 1] = true;
				
				pq.offer(new int[] { upUsed, downUsed, x,
				y + 1 });
			}
		}
		
		int ans = 0;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (visited[i][j]) {
					ans++;
				}
			}
		}
		
		return ans;
	}
	
	private boolean isValid(int r, int c, int n, int m) {
		return r >= 0 && r < n && c >= 0 && c < m;
	}
}

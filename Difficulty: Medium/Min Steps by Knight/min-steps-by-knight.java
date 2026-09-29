class Solution {
	public int minStepToReachTarget(int knightPos[], int targetPos[], int n) {
		int[][] moves = {
			{2, 1}, {2, -1}, {-2, 1}, {-2, -1},
			{1, 2}, {1, -2}, {-1, 2}, {-1, -2}
		};
		
		Queue<int[]> q = new LinkedList<>();
		boolean[][] visited = new boolean[n][n];
		
		q.offer(new int[] {knightPos[0] - 1, knightPos[1] - 1, 0});
		visited[knightPos[0] - 1][knightPos[1] - 1] = true;
		
		while (!q.isEmpty()) {
			int[] curr = q.poll();
			int x = curr[0];
			int y = curr[1];
			int k = curr[2];
			
			if (x == targetPos[0] - 1 && y == targetPos[1] - 1) {
				return k;
			}
			
			for (int[] move: moves) {
				int nX = x + move[0];
				int nY = y + move[1];
				int nK = k + 1;
				
				if (0 <= nX && nX < n && 0 <= nY && nY < n && !visited[nX][nY]) {
					q.offer(new int[] {nX, nY, nK});
					visited[nX][nY] = true;
				}
			}
		}
		
		return - 1;
	}
}

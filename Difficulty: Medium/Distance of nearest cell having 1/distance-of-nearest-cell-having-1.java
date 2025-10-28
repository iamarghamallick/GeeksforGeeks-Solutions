class Solution {
    public ArrayList<ArrayList<Integer>> nearest(int[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        Queue<int[]> q = new LinkedList<>();
        boolean[][] visited = new boolean[n][m];
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>(n);
        for (int i=0; i<n; i++) {
            ArrayList<Integer> row = new ArrayList<>();
            for (int j=0; j< m; j++) row.add(0);
            ans.add(row);
        }
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 1) {
                    q.add(new int[] {i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        
        int[][] dirs = { {0, 1}, {0, -1}, {1, 0}, {-1, 0} };
        
        while(!q.isEmpty()) {
            int[] temp = q.poll();
            int i = temp[0];
            int j = temp[1];
            int dist = temp[2];
            ans.get(i).set(j, dist);
            
            for(int[] dir: dirs) {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(isValid(ni, nj, n, m) && !visited[ni][nj]) {
                    q.add(new int[] {ni, nj, dist + 1});
                    visited[ni][nj] = true;
                }
            }
        }
        
        return ans;
    }
    
    private boolean isValid(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}
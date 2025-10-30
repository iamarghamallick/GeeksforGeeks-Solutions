class Solution {
    int[][] dirs = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };
    
    public void fill(char[][] grid) {
        int n = grid.length;
        int m = grid[0].length;
        boolean[][] visited = new boolean[n][m];
        
        // visit the top boundary
        for(int j=0; j<m; j++) 
            if(grid[0][j] == 'O' && !visited[0][j])
                dfs(0, j, n, m, visited, grid);
        // visit the right boundary
        for(int i=0; i<n; i++)
            if(grid[i][m-1] == 'O' && !visited[i][m-1])
                dfs(i, m-1, n, m, visited, grid);
        // visit the bottom boundary
        for(int j=0; j<m; j++)
            if(grid[n-1][j] == 'O' && !visited[n-1][j])
                dfs(n-1, j, n, m, visited, grid);
        // visit the left boundary
        for(int i=0; i<n; i++)
            if(grid[i][0] == 'O' && !visited[i][0])
                dfs(i, 0, n, m, visited, grid);
        
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                if(grid[i][j] == 'O' && !visited[i][j])
                    grid[i][j] = 'X';
    }
    
    private void dfs(int i, int j, int n, int m, boolean[][] visited, char[][] grid) {
        visited[i][j] = true;
        for(int[] dir: dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(isValid(ni, nj, n, m) && grid[ni][nj] == 'O' && !visited[ni][nj])
                dfs(ni, nj, n, m, visited, grid);
        }
    }
    
    private boolean isValid(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
}

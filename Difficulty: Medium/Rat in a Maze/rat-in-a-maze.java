class Solution {
    public ArrayList<String> ratInMaze(int[][] maze) {
        int n = maze.length;
        ArrayList<String> ans = new ArrayList<>();
        ArrayList<Character> path = new ArrayList<>();
        boolean[][] visited = new boolean[n][n];
        
        dfs(0, 0, maze, visited, path, ans);
        
        return ans;
    }
    
    private void dfs(int x, int y, int[][] maze, boolean[][] visited, ArrayList<Character> path, ArrayList<String> ans) {
        int n = maze.length;
        
        if(x == n-1 && y == n-1) {
            StringBuilder sb = new StringBuilder();
            for (Character ch : path) sb.append(ch);
            ans.add(sb.toString());
            return;
        }
        
        visited[x][y] = true;
        
        int[][] dirs = { {1, 0}, {0, -1}, {0, 1}, {-1, 0} };
        char[] dirName = { 'D', 'L', 'R', 'U'};
        
        for(int i=0; i<4; i++) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            
            if(isValid(newX, newY, n) && !visited[newX][newY] && maze[x][y] == 1) {
                path.add(dirName[i]);
                dfs(newX, newY, maze, visited, path, ans);
                path.remove(path.size() - 1);
            }
        }
        
        visited[x][y] = false;
    }
    
    private boolean isValid(int x, int y, int n) {
        return 0 <= x && x < n && 0 <= y && y < n;
    }
}
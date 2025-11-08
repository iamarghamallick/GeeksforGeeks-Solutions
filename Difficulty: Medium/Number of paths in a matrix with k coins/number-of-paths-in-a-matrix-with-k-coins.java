class Solution {
    public int numberOfPath(int[][] mat, int k) {
        int m = mat.length;
        int n = mat[0].length;
        
        int dp[][][] = new int[m][n][k+1];
        
        for(int row[][] : dp)
            for(int col[] : row)
                Arrays.fill(col,-1);
        
        return dfs(mat,k,0,0,m,n,dp);
    }
    
    public int dfs(int mat[][], int k, int i, int j, int m, int n, int dp[][][]) {
        if(i >= m || j >= n || k < 0)
            return 0;
        
        if(i == m-1 && j == n-1 && k == mat[i][j])
            return 1;
        
        if(dp[i][j][k] != -1)
            return dp[i][j][k];
        
        int left = dfs(mat,k-mat[i][j],i,j+1,m,n,dp);
        int down = dfs(mat,k-mat[i][j],i+1,j,m,n,dp);
        
        return dp[i][j][k] = left + down;
    }
}
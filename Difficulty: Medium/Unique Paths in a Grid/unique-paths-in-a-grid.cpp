class Solution {
  public:
    int Solve(vector<vector<int>>&grid,vector<vector<int>>&dp,int i,int j,int n,int m){
      if(i>=n || j>=m || grid[i][j]==1)
      return 0;
      if(i==n-1 && j==m-1)
      return 1;
      if(dp[i][j]!=-1)
      return dp[i][j];
      // Right move
      int ans=0;
      ans+=Solve(grid,dp,i,j+1,n,m);

      // Down move
      ans+=Solve(grid,dp,i+1,j,n,m);
      return dp[i][j]=ans;
    }
    
    int uniquePaths(vector<vector<int>> &grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return Solve(grid,dp,0,0,n,m);
    }
};
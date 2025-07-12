class Solution {
  public:
    int row, col;
    vector<vector<int>> dirs = {
        { -1, 1 }, { 0, 1 }, { 1, 1 }
    };
    vector<vector<int>> dp;
    
    int solve(int i, int j, vector<vector<int>>& mat, int gold) {
        if(i < 0 || j < 0 || i >= row || j >= col) {
            return 0;
        }
        
        if (dp[i][j] != -1)
            return dp[i][j];
        
        int maxGold = 0;
        
        for(auto &dir : dirs) {
            int iNew = i + dir[0];
            int jNew = j + dir[1];
            
            maxGold = max(maxGold, solve(iNew, jNew, mat, gold));
        }
        
        return dp[i][j] = mat[i][j] + maxGold;
    }
    
    int maxGold(vector<vector<int>>& mat) {
        row = mat.size();
        col = mat[0].size();
        
        dp = vector<vector<int>> (row, vector<int> (col, -1));
        int ans = 0;
        
        for(int i=0; i<row; i++) {
            ans = max(ans, solve(i, 0, mat, 0));
        }
        
        return ans;
    }
};
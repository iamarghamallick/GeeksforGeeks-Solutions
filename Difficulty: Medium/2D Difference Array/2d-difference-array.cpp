class Solution {
  public:
    vector<vector<int>> applyDiff2D(vector<vector<int>>& mat,
                                    vector<vector<int>>& opr) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        
        int size = n*m;
        vector<vector<int>>diff(n+1, vector<int>(m+1,0));
        
        for(auto& it: opr) {
            int val = it[0];
            int r1 = it[1];
            int c1 = it[2];
            int r2 = it[3];
            int c2 = it[4];
            
            diff[r1][c1] += val;
            diff[r1][c2+1] -= val;
           
            diff[r2+1][c1] -= val;
            diff[r2+1][c2+1] += val;
            
            //opr = (2, 0,0,2,2)
           
            //   0 0 0 0     2 0 0 -2              2  2  2  0              2 2 2 0
            //   0 0 0 0     0 0 0 0               0  0  0  0              2 2 2 0
            //   0 0 0 0 ==>-2 0 0 +2  ==> row sum -2 -2 -2 0  ==> col sum 0 0 0 0
            //   0 0 0 0     0 0 0 0               0  0   0 0              0 0 0 0
        }
        
        // Row Sum 
        for(int r = 0 ; r < n ; r++) {
            for(int c= 1 ; c < m ; c++) {
                diff[r][c] += diff[r][c-1];
            }
        }
        
        // col Sum
        for(int c = 0 ; c < m ; c++) {
            for(int r = 1 ; r < n ; r++) {
                diff[r][c] += diff[r-1][c];
            }
        }
        
        for(int r = 0 ; r < n ; r++) {
            for(int c = 0 ; c < m ; c++) {
                mat[r][c] += diff[r][c];
            }
        }
        
        return mat;
    }
};
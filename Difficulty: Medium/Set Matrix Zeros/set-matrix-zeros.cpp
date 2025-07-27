class Solution {
  public:
    void setMatrixZeroes(vector<vector<int>> &mat) {
        int rows = mat.size(), cols = mat[0].size();
        unordered_set<int> rowSet, colSet;
        
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(mat[row][col] == 0) {
                    rowSet.insert(row);
                    colSet.insert(col);
                }
            }
        }
        
        for(int row=0; row<rows; row++) {
            for(int col=0; col<cols; col++) {
                if(rowSet.count(row) ||
                    colSet.count(col)) {
                    mat[row][col] = 0;
                }
            }
        }
    }
};
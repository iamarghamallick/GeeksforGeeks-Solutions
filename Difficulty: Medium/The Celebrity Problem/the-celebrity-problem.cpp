class Solution {
  public:
    int celebrity(vector<vector<int>>& mat) {
        int n = mat.size();
        
        for(int i=0; i<n; i++) {
            bool cele = true;
            
            for(int j=0; j<n; j++) {
                if(i == j) continue;
                if(mat[i][j] == 1) {
                    cele = false;
                    break;
                }
            }
            
            if(cele) {
                for(int k=0; k<n; k++) {
                    if(mat[k][i] == 0) {
                        cele = false;
                        break;
                    }
                }
            }
            
            if(cele) return i;
        }
        
        return -1;
    }
};
class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        int n = mat.size();
        int m = mat[0].size();
        bool flag = false;
        
        for(int i=0; i<n; i++)
        {
            sort(mat[i].begin(), mat[i].end());
            
            
            for(int j = 0; j< m; j++)
            {
                 
                if(mat[i][j] > x)
                    flag = false;
                
                else if (mat[i][j] == x)
                {
                    flag = true;
                    break;
                }
            }
            
            if(flag)    break;
        }
        
        return flag;
    }
};

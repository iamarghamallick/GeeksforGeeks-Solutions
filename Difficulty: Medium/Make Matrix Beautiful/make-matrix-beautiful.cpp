class Solution {
  public:
    int balanceSums(vector<vector<int>>& mat) {
        int n = mat.size();
        int maxVal = 0, ans = 0;
        
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=0; j<n; j++) {
                sum += mat[i][j];
            }
            maxVal = max(maxVal, sum);
        }
        
        for(int j=0; j<n; j++) {
            int sum = 0;
            for(int i=0; i<n; i++) {
                sum += mat[i][j];
            }
            maxVal = max(maxVal, sum);
        }
        
        for(int i=0; i<n; i++) {
            int sum = 0;
            for(int j=0; j<n; j++) {
                sum += mat[i][j];
            }
            ans += maxVal - sum;
        }
        
        return ans;
    }
};
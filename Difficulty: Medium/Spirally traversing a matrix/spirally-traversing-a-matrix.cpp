//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<int> ans;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int dr[4] = { 0, 1, 0, -1 };
        int dc[4] = { 1, 0, -1, 0 };
        int r = 0, c = 0;
        int di = 0;
        
        for(int i=0; i<n*m; i++) {
            ans.push_back(mat[r][c]);
            visited[r][c] = true;
            
            int newr = r + dr[di];
            int newc = c + dc[di];
            
            if(0 <= newr && newr < n && 0 <= newc && newc < m && !visited[newr][newc]) {
                r = newr;
                c = newc;
            } else {
                di = (di + 1) % 4;
                r += dr[di];
                c += dc[di];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int r, c;
        cin >> r >> c;
        vector<vector<int>> matrix(r, vector<int>(c, 0));

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix);
        for (int i = 0; i < result.size(); ++i)
            cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
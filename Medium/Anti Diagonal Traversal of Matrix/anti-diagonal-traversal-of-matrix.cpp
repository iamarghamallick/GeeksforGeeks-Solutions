//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> antiDiagonalPattern(vector<vector<int>> mat) 
    {
        // Code here
        int n = mat.size(), k = 0, x = 0;
        vector<int> arr(n*n);
        
        for(int i=0; i<n; i++) {
            k = 0;
            for(int j=i; j>=0; j--)
                arr[x++] = mat[k++][j];
        }
        
        for(int i=1; i<n; i++) {
            k = i;
            for(int j=n-1; j>=i; j--) 
                arr[x++] = mat[k++][j];
        }
        
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> matrix;
        matrix.resize(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> matrix[i][j];
            }
        }

        Solution ob;
        vector<int> ans = ob.antiDiagonalPattern(matrix);
        for (int i = 0; i < ans.size(); ++i) cout << ans[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
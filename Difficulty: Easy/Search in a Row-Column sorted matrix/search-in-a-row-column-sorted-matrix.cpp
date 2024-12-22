//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool matSearch(vector<vector<int>> &mat, int x) {
        int n = mat.size(), m = mat[0].size();
        int i = 0, j = m - 1;
      
        while(i < n && j >= 0) {
            // If x > mat[i][j], then x will be greater
            // than all elements to the left of 
            // mat[i][j] in row i, so increment i
            if(x > mat[i][j])   i++;
          
            // If x < mat[i][j], then x will be smaller
            // than all elements to the bottom of
            // mat[i][j] in column j, so decrement j
            else if(x < mat[i][j])  j--;
          
            // If x = mat[i][j], return true
            else    return true;
        }
        
        return false;
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
        int x;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                cin >> matrix[i][j];
            }
        }
        cin >> x;
        Solution ob;
        bool an = ob.matSearch(matrix, x);
        if (an)
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            bool flag = true;
            for(int j=0; j<n; j++) {
                if(mat[i][j])   flag = false;
            }
            if(flag && isKnownToAll(mat, i))
                return i;
        }
        
        return -1;
    }
    
  private:
    bool isKnownToAll(vector<vector<int>> &mat, int i) {
        int n = mat.size();
        for(int j=0; j<n; j++) {
            if(i == j)  continue;
            if(!mat[j][i])  return false;
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    vector<string> ans;
    
    int row[4] = {1, -1, 0, 0};
    int col[4] = {0, 0, 1, -1};
    string dir[4] = {"D", "U", "R", "L"};
    
    void solve(int r, int c, vector<vector<int>> &mat, string path, vector<vector<bool>> &visited) {
        int n = mat.size();
        
        if(r == n-1 && c == n-1) {
            ans.push_back(path);
            return;
        }
        
        for(int k=0; k<4; k++) {
            int nr = row[k] + r;
            int nc = col[k] + c;
            string ndir = dir[k];
            
            if(nr >= 0 && nr < n && nc >= 0 && nc < n && mat[nr][nc] && !visited[nr][nc]) {
                visited[nr][nc] = true;
                solve(nr, nc, mat, path + ndir, visited);
                visited[nr][nc] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &mat) {
        vector<vector<bool>> visited(mat.size(), vector<bool>(mat.size(), false));
        if(mat[0][0]) {
            visited[0][0] = true;
            solve(0, 0, mat, "", visited);
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
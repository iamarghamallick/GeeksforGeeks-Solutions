//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    pair<int, int> dir(string d) {
        if(d == "left")  return make_pair(0, -1);
        if(d == "right") return make_pair(0, 1);
        if(d == "up")    return make_pair(-1, 0);
        return make_pair(1, 0); // if(d == "down")
    }
    
    string moveRight(string d) {
        if(d == "left")  return "up";
        if(d == "right") return "down";
        if(d == "up")    return "right";
        return "left"; // if(d == "down")
    }
    
    vector<int> FindExitPoint(int n, int m, vector<vector<int>>& mat) {
        string currDir = "right";
        vector<int> ans(2);
        int i = 0, j = 0;
        
        do {
            ans[0] = i; ans[1] = j;
            
            if(mat[i][j] == 1) {
                mat[i][j] = 0;
                currDir = moveRight(currDir);
            }
            
            i += dir(currDir).first;
            j += dir(currDir).second;
            
        } while(i >= 0 && i < mat.size() && j >= 0 && j < mat[0].size());
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> matrix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> matrix[i][j];
        Solution obj;
        vector<int> ans = obj.FindExitPoint(n, m, matrix);
        for (auto i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dirs[8][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, -1}, {-1, 1}, {1, 1}, {1, -1}};
    
    bool range(int i, int j, int n, int m) {
        return 0 <= i && i < n && 0 <= j && j < m;
    }
    
    void dfs(int i, int j, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
        int n = grid.size();
        int m = grid[0].size();
        visited[i][j] = true;
        for(auto dir : dirs) {
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(range(ni, nj, n, m) && grid[ni][nj] == 'L' && !visited[ni][nj]) {
                visited[ni][nj] = true;
                dfs(ni, nj, grid, visited);
            }
        }
    }
    
    // Function to find the number of islands.
    int countIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int islandCount = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(grid[i][j] == 'L' && !visited[i][j]) {
                    visited[i][j] = true;
                    dfs(i, j, grid, visited);
                    islandCount++;
                }
            }
        }
        return islandCount;
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.countIslands(grid);
        cout << ans << '\n';

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
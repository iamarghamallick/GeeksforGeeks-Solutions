//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int m, n;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    
    void dfs(vector<vector<int>>& image, int i, int j, int val,int currColor) {
        if(i < 0 || i >= m || j < 0 || j >= n || image[i][j] != currColor) {
            return;
        }
        image[i][j] = val;
        
        for(auto& dir : directions){
            int x = i + dir[0];
            int y = j + dir[1];
            dfs(image,x,y,val,currColor);
        }
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        m = image.size();
        n = image[0].size();
        int currColor = image[sr][sc];
        if(currColor != newColor){
            dfs(image,sr,sc,newColor,currColor); 
        }
        return image;
    }
};


//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> image(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> image[i][j];
        }
        int sr, sc, newColor;
        cin >> sr >> sc >> newColor;
        Solution obj;
        vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
        for (auto i : ans) {
            for (auto j : i)
                cout << j << " ";
            cout << "\n";
        }

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
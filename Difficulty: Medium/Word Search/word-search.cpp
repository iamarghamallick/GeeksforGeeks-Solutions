//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    bool solve(int i,int j,int ind,vector<vector<int>> &vis,vector<vector<char>>& mat, string& word){
        if(ind==word.size())
        return true;
        
        int n=mat.size(),m=mat[0].size();
        
        vis[i][j]=true;
        
        int dr[] = {-1,1,0,0};
        int dc[] = {0,0,-1,1};
    
        for(int k=0;k<4;k++){
            int row = i + dr[k];
            int col = j + dc[k];
            
            if(row>=0 && row<n && col>=0 && col<m && !vis[row][col] && mat[row][col]==word[ind] ){
                if(solve(row,col,ind+1,vis,mat,word))
                return true;
            }
        }
        
        vis[i][j]=0;
        return false;
    }
    bool isWordExist(vector<vector<char>>& mat, string& word) {
         int n=mat.size(),m=mat[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==word[0])
                  if(solve(i,j,1,vis,mat,word))
                    return true;
            }
        }
        
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> mat(n, vector<char>(m, '*'));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        string word;
        cin >> word;
        Solution obj;
        bool ans = obj.isWordExist(mat, word);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
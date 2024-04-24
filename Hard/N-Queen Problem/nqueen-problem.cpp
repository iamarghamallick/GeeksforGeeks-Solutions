//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    vector<vector<int>> ans;
    
    bool isSafe(int row, int col, int n, vector<vector<int>> &board) {
        // Check this row on left side
        for(int i=0; i<col; i++)
            if(board[row][i])
                return false;
        
        // Check upper diagonal on left side
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
            if (board[i][j])
                return false;
 
        // Check lower diagonal on left side
        for (int i = row, j = col; j >= 0 && i < n; i++, j--)
            if (board[i][j])
                return false;
 
        return true;
    }
    
    void solve(int col, int n, vector<vector<int>> &board, vector<int> &res) {
        if(col >= n) {
            ans.push_back(res);
            return;
        }
            
        for(int i=0; i<n; i++) {
            if(isSafe(i, col, n, board)) {
                board[i][col] = 1;
                res.push_back(i+1);
                
                solve(col+1, n, board, res);
                
                // BACKTRACK
                board[i][col] = 0;
                res.pop_back();
            }
        }
    }
    
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<int> res;
        
        solve(0, n, board, res);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
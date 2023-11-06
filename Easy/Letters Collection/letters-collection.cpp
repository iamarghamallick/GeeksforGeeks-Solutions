//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> matrixSum(int n, int m, vector<vector<int>> mat, int q, vector<int> queries[])
    {
        // code here
        vector<int> ans;
        
        for(int i=0; i<q; i++) {
            int row = queries[i][1];
            int col = queries[i][2];
            int sum = 0;
            
            if(queries[i][0] == 1) {
                if(row - 1 >= 0 && col - 1 >= 0)
                    sum += mat[row - 1][col - 1] ;
                    
                if(row - 1 >= 0)
                    sum += mat[row - 1][col] ;
                    
                if(row - 1 >= 0 && col + 1 < m)
                    sum += mat[row - 1][col + 1] ;
                    
                if(col + 1 < m)
                    sum += mat[row][col + 1] ;
                    
                if(row + 1 < n && col + 1 < m)
                    sum += mat[row + 1][col + 1] ;
                    
                if(row + 1 < n)
                    sum += mat[row + 1][col] ;
                    
                if(row + 1 < n && col - 1 >= 0)
                    sum += mat[row + 1][col - 1] ;
                    
                if(col - 1 >= 0)
                    sum += mat[row][col - 1] ;
            } else {
                if(row - 2 >= 0 && col - 2 >= 0)
                    sum += mat[row - 2][col - 2] ;
                    
                if(row - 2 >= 0 && col - 1 >= 0)
                    sum += mat[row - 2][col - 1] ;
                    
                if(row - 2 >= 0)
                    sum += mat[row - 2][col] ;
                    
                if(row - 2 >= 0 && col + 1 < m)
                    sum += mat[row - 2][col + 1] ;
                    
                if(row - 2 >= 0 && col + 2 < m)
                    sum += mat[row - 2][col + 2] ;
                    
                if(row - 1 >= 0 && col + 2 < m)
                    sum += mat[row - 1][col + 2] ;
                    
                if(col + 2 < m)
                    sum += mat[row][col + 2] ;
                    
                if(row + 1 < n && col + 2 < m)
                    sum += mat[row + 1][col + 2] ;
                    
                if(row + 2 < n && col + 2 < m)
                    sum += mat[row + 2][col + 2] ;
                    
                if(row + 2 < n && col + 1 < m)
                    sum += mat[row + 2][col + 1] ;
                    
                if(row + 2 < n)
                    sum += mat[row + 2][col] ;
                    
                if(row + 2 < n && col - 1 >= 0)
                    sum += mat[row + 2][col - 1] ;
                    
                if(row + 2 < n && col - 2 >= 0)
                    sum += mat[row + 2][col - 2] ;
                    
                if(row + 1 < n && col - 2 >= 0)
                    sum += mat[row + 1][col - 2] ;
                    
                if(col - 2 >= 0)
                    sum += mat[row][col - 2] ;
                    
                if(row - 1 >= 0 && col - 2 >= 0)
                    sum += mat[row - 1][col - 2] ;
            }
            ans.push_back(sum);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m, q, ty, i, j;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++)
            for(int j = 0;j < m;j++)
                cin>>mat[i][j];
        cin>>q;
        vector<int> queries[q];
        for(int k = 0;k < q;k++){
            cin>>ty>>i>>j;
            queries[k].push_back(ty);
            queries[k].push_back(i);
            queries[k].push_back(j);
        }
        
        Solution ob;
        vector<int> ans = ob.matrixSum(n, m, mat, q, queries);
        for(int u: ans)
            cout<<u<<"\n";
    }
    return 0;
}
// } Driver Code Ends
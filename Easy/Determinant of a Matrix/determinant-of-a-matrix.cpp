//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends


class Solution
{   
    public:
    //Function for finding determinant of matrix.
    int determinantOfMatrix(vector<vector<int> > mat, int n)
    {
        // code here 
        if(n == 1)  return mat[0][0];
        if(n == 2)  return mat[0][0]*mat[1][1] - mat[0][1]*mat[1][0];
        
        int det = 0;
        
        for(int i=0; i<n; i++) {
            int cof = (int)pow(-1, i) * mat[0][i] * determinantOfMatrix(subMatrix(mat, 0, i), n-1);
            det += cof;
        }
        
        return det;
    }
    
    vector<vector<int>> subMatrix(vector<vector<int>> mat, int r, int c) {
        int n = mat.size();
        vector<vector<int>> arr(n-1, vector<int>(n-1));
        int row = 0, col = 0;
        
        for(int i=0; i<n; i++) {
            if(i != r) {
                for(int j=0; j<n; j++) {
                    if(j != c) {
                        arr[row][col] = mat[i][j];
                        col++;
                    }
                }
                col = 0;
                row++;
            }
        }
        
        return arr;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int n;
        cin>>n;
        vector<vector<int> > matrix(n); 

        for(int i=0; i<n; i++)
        {
            matrix[i].assign(n, 0);
            for( int j=0; j<n; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        int result = ob.determinantOfMatrix(matrix, n);
        cout<<result<<endl;
    }
    return 0;
}
// } Driver Code Ends
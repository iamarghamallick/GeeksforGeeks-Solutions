//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution {
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string X, string Y, int m, int n) {
        // DP: Mother Problem : Longest Common Subsequence (LCS)
        // Answer : (m + n - |LCS|)
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) // initialization
                    dp[i][j] = 0;
                    
                // main logic
                else if(X[i-1] == Y[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        // PRINTING Shortest Common Supersequence
        // string s = "";
        // int i = m, j = n;
        
        // while(i > 0 && j > 0) {
        //     if(X[i-1] == Y[j-1]) {
        //         s += X[i-1];
        //         i--; j--;
        //     }
            
        //     // Notice the code variation here with
        //     // with printing LCS problem
        //     else if(dp[i][j-1] > dp[i-1][j]) {
        //         s += Y[j-1];
        //         j--;
        //     } else {
        //         s += X[i-1];
        //         i--;
        //     }
        // }
        
        // // include the remaining chars of X or Y (if any)
        // while(i > 0) {
        //     s += X[i-1];
        //     i--;
        // }
        // while(j > 0) {
        //     s += Y[j-1];
        //     j--;
        // }
        
        // // finally reverse the string s to find required SCS
        // reverse(s.begin(), s.end());
        
        // cout << s;
        
        return m + n - dp[m][n];
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
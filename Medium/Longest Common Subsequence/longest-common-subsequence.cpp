//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution {
    public:
    //Function to find the length of longest common subsequence in two strings.
    // Recursive Approch. Result -> Time Limit Exceeded!!
    // int lcs(int n, int m, string s1, string s2) {
    //     // Base Case
    //     if(n == 0 || m == 0)
    //         return 0;
        
    //     // recursive calls
    //     if(s1[n-1] == s2[m-1])
    //         return 1 + lcs(n-1, m-1, s1, s2);
            
    //     return max(lcs(n-1, m, s1, s2), lcs(n, m-1, s1, s2));
    // }
    
    // Dynamic Programming Approch
    // Recursion with memoization. (May cause stack overflow problem, Also exceeding time limit here)
    // int dp[1001][1001];
    
    // int solver(int n, int m, string s1, string s2) {
    //     if(n == 0 || m == 0)
    //         return 0;
        
    //     // check if the required call is already done previously
    //     if(dp[n][m] != -1)
    //         return dp[n][m];
            
    //     if(s1[n-1] == s2[m-1])
    //         return dp[n][m] = 1 + solver(n-1, m-1, s1, s2);
        
    //     return dp[n][m] = max(solver(n-1, m, s1, s2), solver(n, m-1, s1, s2));
    // }
    
    // int lcs(int n, int m, string s1, string s2) {
    //     // Using dp[][] array table with solver function
    //     // initialization of dp array with -1
    //     // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        
    //     memset(dp, -1, sizeof(dp));
        
    //     return solver(n, m, s1, s2);
    // }
    
    // Top-down approch. Best solution
    int lcs(int n, int m, string s1, string s2) {
        // your code here
        int dp[n+1][m+1];
        
        // initialization
        for(int i=0; i<=n; i++)
            dp[i][0] = 0;
        for(int j=0; j<=m; j++)
            dp[0][j] = 0;
            
        // next part
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=m; j++) {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[n][m];
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends
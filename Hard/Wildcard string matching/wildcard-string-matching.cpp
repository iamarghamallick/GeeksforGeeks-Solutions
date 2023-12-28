//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool match(string wild, string pattern) {
        // code here
        int m = wild.length(); 
        int n = pattern.length(); 
         
        // Create a DP table to store the results of subproblems 
        bool dp[m+1][n+1]; 
         
        // Initialize the DP table 
        memset(dp, false, sizeof(dp)); 
         
        // Empty pattern can match with empty wild string 
        dp[0][0] = true; 
         
        // Only '*' can match with empty string 
        for (int i = 1; i <= m; i++) { 
            if (wild[i-1] == '*') 
                dp[i][0] = dp[i-1][0]; 
        } 
         
        // Fill the DP table in bottom-up manner 
        for (int i = 1; i <= m; i++) { 
            for (int j = 1; j <= n; j++) { 
                // If current characters match, or wild contains '?' 
                if (wild[i-1] == pattern[j-1] || wild[i-1] == '?') 
                    dp[i][j] = dp[i-1][j-1]; 
                 
                // If wild contains '*' 
                else if (wild[i-1] == '*') 
                    dp[i][j] = dp[i-1][j] || dp[i][j-1]; 
            } 
        } 
         
        return dp[m][n]; 
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends
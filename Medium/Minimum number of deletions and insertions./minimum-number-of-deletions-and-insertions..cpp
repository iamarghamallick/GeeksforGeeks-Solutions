//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
	int minOperations(string str1, string str2) { 
	    // DP : Mother Problem - Longest Common Subsequence
	    // No. of deletion = |str1| - |LCS|
	    // No. of insertion = |str2| - |LCS|
	    int m = str1.size();
	    int n = str2.size();
	    
	    int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) // initialization
                    dp[i][j] = 0;
                    
                // main logic
                else if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        int noOfDeletion = m - dp[m][n];
        int noOfInsertion = n - dp[m][n];
        
        return noOfDeletion + noOfInsertion;
	}
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends
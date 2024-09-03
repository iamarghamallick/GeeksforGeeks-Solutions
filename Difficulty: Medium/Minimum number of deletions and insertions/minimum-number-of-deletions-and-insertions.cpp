//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int lcs(int m, int n, string s1, string s2) {
	    int dp[m+1][n+1];
	    
	    for(int i=0; i<=m; i++) {
	        for(int j=0; j<=n; j++) {
	            if(i == 0 || j == 0)
	                dp[i][j] = 0;
	                
	            else if(s1[i-1] == s2[j-1])
	                dp[i][j] = dp[i-1][j-1] + 1;
	                
	            else 
	                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
	        }
	    }
	    
	    return dp[m][n];
	}
	
	int minOperations(string str1, string str2) { 
	    int m = str1.size();
	    int n = str2.size();
	    int len = lcs(m, n, str1, str2);
	    return (m - len) + (n - len);
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
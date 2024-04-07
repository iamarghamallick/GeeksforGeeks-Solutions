//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	public:
	int maxDotProduct(int n, int m, int a[], int b[]) { 
		// Create 2D Matrix that stores dot product
        // dp[i+1][j+1] stores product considering B[0..i]
        // and A[0...j]. Note that since all m > n, we fill
        // values in upper diagonal of dp[][]
        int dp[m+1][n+1];
        memset(dp, 0, sizeof(dp));
 
        // Traverse through all elements of b[]
        for (int i=1; i<=m; i++)
            // Consider all values of a[] with indexes greater
            // than or equal to i and compute dp[i][j]
            for (int j=i; j<=n; j++)
                // Two cases arise
                // 1) Include a[j]
                // 2) Exclude b[j] (insert 0 in B[]) 
                dp[i][j] = max((dp[i-1][j-1] + (a[j-1] * b[i-1])), dp[i][j-1]);
 
        return dp[m][n];
	} 
};


//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n], b[m];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

        for(int i = 0; i < m; i++)
        	cin >> b[i];

       

	    Solution ob;
	    cout << ob.maxDotProduct(n, m, a, b) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
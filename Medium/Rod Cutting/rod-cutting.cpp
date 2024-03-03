//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
    int cutRod(int price[], int n) {
        //code here
        // this is the same problem as 0 / 1 knapsack with allowed repeation
        // where wt[] === length[] = {1,2,3,...,n-1}
        // and val[] === price[]
        // with W === N
        
        // initializing dp array
        int dp[n+1][n+1];
        
        for(int i=0; i<=n; i++) {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }
        
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=n; j++) {
                // here length[i] = i
                if(i <= j) {
                    // we have two choise 
                    dp[i][j] = max(price[i-1] + dp[i][j - i], dp[i-1][j]);
                } else {
                    // no choise -> cannot include
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends
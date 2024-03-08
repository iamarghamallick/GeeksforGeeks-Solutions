//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int minCoins(vector<int> &coins, int n, int sum) { 
        // Your code goes here
	    int dp[n+1][sum+1];
	    
	    // initialization
	    for(int j=0; j<=sum; j++)
	        dp[0][j] = INT_MAX - 1;
	    for(int i=1; i<=n; i++)
	        dp[i][0] = 0;
	        
	    //here in this problem we need to initialize the 2nd row also
	    for(int j=1; j<=sum; j++) {
	        if(j % coins[0] == 0)
	            dp[1][j] = j / coins[0];
	        else
	            dp[1][j] = INT_MAX - 1;
	    }
	    
	    // main logic
	    for(int i=2; i<=n; i++) {
	        for(int j=0; j<=sum; j++) {
	            if(coins[i-1] <= j) {
	                dp[i][j] = min(1 + dp[i][j - coins[i-1]], dp[i-1][j]);
	            } else {
	                dp[i][j] = dp[i-1][j];
	            }
	        }
	    }
	    
	    return dp[n][sum] == INT_MAX - 1 ? -1 : dp[n][sum];
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        vector<int> coins(m);
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long int count(int coins[], int n, int sum) {
        // code here.
        long long int dp[n+1][sum+1];
        
        // initialization
        for(int i=0; i<=n; i++)
            dp[i][0] = 1;
        for(int j=1; j<=sum; j++)
            dp[0][j] = 0;
            
        // main logic
        for(int i=1; i<=n; i++) {
            for(int j=0; j<=sum; j++) {
                if(coins[i-1] <= j) {
                    // we have two choise
                    dp[i][j] = dp[i][j - coins[i-1]] + dp[i-1][j];
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends
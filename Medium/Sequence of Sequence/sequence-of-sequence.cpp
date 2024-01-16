//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int numberSequence(int m, int n){
        // code here
        vector<vector<int>> dp(n, vector<int> (m + 1, 0));

        for(int i = 1; i < m + 1; i++)
            dp[n - 1][i] = 1;

        for(int i = n - 2; i > -1; i--)
            for(int j = 1; j < m + 1; j++)
                for(int k = 2 * j; k < m + 1; k++)
                    dp[i][j] += dp[i + 1][k];

        return accumulate(dp[0].begin(), dp[0].end(), 0);
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int m, n;
        cin>>m>>n;
        
        Solution ob;
        cout<<ob.numberSequence(m, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    // Function to find minimum number of attempts needed in 
    // order to find the critical floor.
    
    // // Approch1 : Only Recursion
    // int solve(int e, int f) {
    //     // Base Cases
    //     if(f == 1)    return f;
    //     if(e == 1)  return f;
        
    //     int ans = INT_MAX;
        
    //     // Next Logic
    //     for(int k=1; k<=f; k++) {
    //         int tempAns = 1 + max(solve(e-1, k-1), solve(e, f-k));
    //         ans = min(ans, tempAns);
    //     }
        
    //     return ans;
    // }
    
    // Approch2 : Recursion with Memoization
    int dp[201][201];
    
    int solve(int e, int f) {
        // Base Cases
        if(f == 0 || f == 1)    return f;
        if(e == 1)  return f;
        
        int ans = INT_MAX;
        
        if(dp[e][f] != -1)
            return dp[e][f];
        
        // Next Logic
        for(int k=1; k<=f; k++) {
            int tempAns = 1 + max(solve(e-1, k-1), solve(e, f-k));
            ans = min(ans, tempAns);
        }
        
        return dp[e][f] = ans;
    }
    
    int eggDrop(int n, int k) {
        memset(dp, -1, sizeof(dp));
        return solve(n, k);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
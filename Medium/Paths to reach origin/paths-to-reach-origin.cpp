//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution {
public:
    int dp[501][501];
    
    int solve(int x, int y) {
        if(x == 0 || y == 0)
            return 1;
            
        if(dp[x][y])
            return dp[x][y];
        
        return dp[x][y] = (solve(x-1, y) + solve(x, y-1)) % 1000000007;
    }
    
    int ways(int x, int y) {
        memset(dp, 0, sizeof(dp));
        return solve(x, y);
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y;
        cin>>x>>y;
        Solution ob;
        cout<<ob.ways(x,y)<<endl;
    }
	return 0;
}

// } Driver Code Ends
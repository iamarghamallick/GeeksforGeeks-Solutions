//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution {
    public:
    int dp[10001];
    
    int solve(int n, int x, int y, int z) {
        if(n == 0)
            return 0;
            
        if(dp[n] != -1)
            return dp[n];
        
        int a = x <= n ? solve(n - x, x, y, z) : INT_MIN;
        int b = y <= n ? solve(n - y, x, y, z) : INT_MIN;
        int c = z <= n ? solve(n - z, x, y, z) : INT_MIN;
        
        return dp[n] = 1 + max({a, b, c});
    }
    
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(n, x, y, z);
        return ans < 0 ? 0 : ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends
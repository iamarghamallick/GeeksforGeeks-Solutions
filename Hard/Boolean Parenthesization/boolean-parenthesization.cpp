//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int solve(string s, int i, int j, int isTrue) {
    //     // Base Condition
    //     if(i > j)   return 0;
    //     if(i == j) {
    //         if(isTrue == 1)
    //             return s[i] == 'T';
    //         else
    //             return s[i] == 'F';
    //     }
        
    //     // Next Logic
    //     int ans = 0;
            
    //     for(int k=i+1; k<=j-1; k+=2) {
    //         int LT = solve(s, i, k-1, 1);
    //         int LF = solve(s, i, k-1, 0);
    //         int RT = solve(s, k+1, j, 1);
    //         int RF = solve(s, k+1, j, 0);
            
    //         if(s[k] == '&') {
    //             if(isTrue == 1)
    //                 ans += LT * RT;
    //             else 
    //                 ans += LF * RF + LF * RT + LT * RF;
    //         } else if(s[k] == '|') {
    //             if(isTrue == 1)
    //                 ans += LF * RT + LT * RF + LT * RT;
    //             else
    //                 ans += LF * RF;
    //         } else if(s[k] == '^') {
    //             if(isTrue == 1)
    //                 ans += LF * RT + LT * RF;
    //             else 
    //                 ans += LF * RF + LT * RT;
    //         }
    //     }
        
    //     return ans;
    // }
    
    // Recursion with Memoization
    int dp[201][201][2];
    
    int solve(string s, int i, int j, int isTrue) {
        // Base Condition
        if(i > j)   return 0;
        if(i == j) {
            if(isTrue == 1)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }
        
        // Next Logic
        int ans = 0;
        
        if(dp[i][j][isTrue] != -1)
            return dp[i][j][isTrue];
            
        for(int k=i+1; k<=j-1; k+=2) {
            int LT, LF, RT, RF;
            
            if(dp[i][k-1][1] != -1)
                LT = dp[i][k-1][1];
            else 
                LT = solve(s, i, k-1, 1);
                
            if(dp[i][k-1][0] != -1)
                LF = dp[i][k-1][0];
            else 
                LF = solve(s, i, k-1, 0);
                
            if(dp[k+1][j][1] != -1)
                RT = dp[k+1][j][1];
            else 
                RT = solve(s, k+1, j, 1);
            
            if(dp[k+1][j][0] != -1)
                RF = dp[k+1][j][0];
            else 
                RF = solve(s, k+1, j, 0);
            
            if(s[k] == '&') {
                if(isTrue == 1)
                    ans += LT * RT;
                else 
                    ans += LF * RF + LF * RT + LT * RF;
            } else if(s[k] == '|') {
                if(isTrue == 1)
                    ans += LF * RT + LT * RF + LT * RT;
                else
                    ans += LF * RF;
            } else if(s[k] == '^') {
                if(isTrue == 1)
                    ans += LF * RT + LT * RF;
                else 
                    ans += LF * RF + LT * RT;
            }
        }
        
        return dp[i][j][isTrue] = ans % 1003;
    }
    
    int countWays(int n, string s){
        memset(dp, -1, sizeof(dp));
        return solve(s, 0, n-1, true);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.countWays(n, s)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // int mod=1e9+7;

    // long long power(long long a,long long b){
    //     long long ans=1;
    //     while(b){
    //         if(b%2)ans*=a;
    //         b>>=1;
    //         a*=a;
    //         a%=mod;
    //         ans%=mod;
    //     }
    //     return ans;
    // }
    
    // long long solve(int n,vector<int> &dp){
    //     if(n==2) return 1;
    //     if(n==3) return 3;
    //     if(dp[n]!=-1)return dp[n];
    //     return dp[n]=((solve(n-1,dp) + power(2,n-2))%mod+ solve(n-2,dp))%mod;
    // }
    
    // int numberOfConsecutiveOnes(int n) {
    //     vector<int> dp(n+1,-1);
    //     return solve(n,dp);
    // }
    
    int numberOfConsecutiveOnes(int n) {
        const long long MOD = 1'000'000'007;
        if (n == 1 || n == 2)
            return 1;

        long long a = 1, b = 1;
        long long res = 1;
        for (int i = 3; i <= n; i++) {
            long long c = (a + b) % MOD;
            a = b;
            b = c;
            res = (res * 2 + a) % MOD;
        }
        return (int)res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.numberOfConsecutiveOnes(N) << endl;
    }
    return 0;
}

// } Driver Code Ends
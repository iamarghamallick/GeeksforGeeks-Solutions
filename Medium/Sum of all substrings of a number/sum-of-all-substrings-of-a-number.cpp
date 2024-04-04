//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    public:
    
    int toDigit(char c) {
        return (c - '0');
    }
    
    const long long int mod = 1e9+7;
    
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string num) {
        // DP Approch
        int n = num.length();
        
        long long int dp[n];
        
        dp[0] = toDigit(num[0]);
        
        long long int ans = dp[0];
        
        for(int i=1; i<n; i++) {
            // sumofdigit[i]  =  (i+1)*num[i] + 10*sumofdigit[i-1]
            dp[i] = ((i+1) * toDigit(num[i]) + 10 * dp[i-1]) % mod;
            ans += dp[i];
            ans %= mod;
        }
        
        return ans;
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
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    }
    return 0;
}

// } Driver Code Ends
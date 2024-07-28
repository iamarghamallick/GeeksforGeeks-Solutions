//{ Driver Code Starts
//Initial template for c++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
public:
    long long int nthMagicNo(int n) {
        long long int mod = 1000000007;
        long long int pow = 1, ans = 0;
        while (n) {
            pow *= 5 % mod;
            if (n & 1)
                ans += pow % mod;
            n >>= 1;
        }
        return ans % mod;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.nthMagicNo(n) << endl;
    
    }
    return 0; 
} 
// } Driver Code Ends
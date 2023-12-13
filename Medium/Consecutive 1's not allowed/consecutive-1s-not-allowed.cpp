//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;
#define ll long long

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	// #define ll long long
	ll countStrings(int n) {
	    // code here
	    if(n == 1) return 2;
	    
	    ll one = 1, zero = 1, total = one+zero;
	    
	    while(n-- > 1) {
	        one = zero;
	        zero = total;
	        total = (one+zero) % 1000000007;
	    }
	    
	    return total % 1000000007;
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.countStrings(n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends
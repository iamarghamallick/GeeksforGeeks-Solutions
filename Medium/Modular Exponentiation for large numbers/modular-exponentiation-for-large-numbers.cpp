//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	long long int PowMod(long long int x, long long int n, long long int M) {
        int ans = 1;
        x = x % M; // Update x if it is more than or equal to p
  
        if(x == 0) return 0; // In case x is divisible by p
 
        while (n > 0) {
            // If y is odd, multiply x with result 
            if (n & 1)
                ans = (ans * x) % M;
 
            // y must be even now
            n >>= 1; // y = y/2
            x = (x * x) % M;
        }
        
        return ans;
	}
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	long long int x, n, m;
    	cin >> x >> n >> m;
    	Solution ob;
    	long long int ans = ob.PowMod(x, n, m);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends
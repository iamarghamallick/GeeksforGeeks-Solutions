//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    long long reversedBits(long long x) {
        long long rev = 0;
        
        for(int i=1; i<=32; i++) {
            rev <<= 1;
            if(x & 1 == 1)
                rev ^= 1;
            x >>= 1;
        }
        
        return rev;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long X;
        
        cin>>X;

        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
// } Driver Code Ends
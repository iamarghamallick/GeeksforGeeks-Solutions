//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int firstElement(int n) {
        // Fibonacci series problem
        
        // for n = 1 -> a10 = 1
        // for n = 2 -> a10 = 1
        // for n = 3 -> a10 = 2
        // for n = 4 -> a10 = 3
        // for n = 5 -> a10 = 5
        //  ...  ...  ...  ...
        //  ...  ...  ...  ...
        // for n = n -> a10 = (n-1)th + (n-2)th
        
        int prev = 1;
        int curr = 1;
        int next;
        
        for(int i=2; i<n; i++) {
            next = (prev + curr) % 1000000007;
            prev = curr;
            curr = next;
        }
        
        return curr;
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
        cout << ob.firstElement(n) << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
#define ll long long

class Solution {
  public:
    long long pairAndSum(int n, long long arr[]) {
        ll ans = 0;
        for(ll i=0; i<32; i++) {
            ll k = 0;
            for(ll j=0; j<n; j++)
                if(arr[j] & (1<<i))
                    k++; 
            
            ans += (1<<i) * (((k) * (k-1)) / 2); 
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        long long Arr[N];
        for (int i = 0; i < N; i++) {
            cin >> Arr[i];
        }
        Solution ob;
        cout << ob.pairAndSum(N, Arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
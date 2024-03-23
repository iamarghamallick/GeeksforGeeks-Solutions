//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int mod = 1000000007;
    
    vector<int> Series(int n) {
        vector<int> ans;
        ans.push_back(0);
        ans.push_back(1);
        
        for(int i=2; i<=n; i++)
            ans.push_back((ans[i-2] + ans[i-1]) % mod);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution obj;

        vector<int> ans = obj.Series(n);
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
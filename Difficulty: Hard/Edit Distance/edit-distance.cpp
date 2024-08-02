//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[100 + 1][100 + 1];
  
    int editDistance(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        memset(dp, -1, sizeof(dp));
        return solve(str1, str2, n-1, m-1);
    }
    
    int solve(string &s1, string &s2, int i, int j) {
        if(i == -1)
            return j +1;
        if(j == -1)
            return i +1;
        if(dp[i][j] != -1)
            return dp[i][j];

        int ins = 0, del = 0, rep = 0;
        
        if(s1[i] != s2[j]) {
            ins = 1 + solve(s1, s2, i, j -1);
            del = 1 + solve(s1, s2, i -1, j);
            rep = 1 + solve(s1, s2, i-1, j-1);
            
            return dp[i][j] = min(ins, min(del, rep));
        }
        
        return dp[i][j] = solve(s1, s2, i-1, j-1);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends
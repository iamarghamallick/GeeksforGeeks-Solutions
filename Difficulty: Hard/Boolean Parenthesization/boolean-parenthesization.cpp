//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++
class Solution {
  public:
    int f(int i, int j, bool isTrue, string &s, vector<vector<vector<int>>> &dp) {
        if (i > j) return 0;
        if (i == j) {
            if (isTrue)
                return s[i] == 'T';
            else
                return s[i] == 'F';
        }

        if (dp[i][j][isTrue] != -1) return dp[i][j][isTrue];

        int ways = 0;
        for (int ind = i + 1; ind < j; ind += 2) {
            int lT = f(i, ind - 1, true, s,dp);
            int lF = f(i, ind - 1, false, s,dp);
            int rT = f(ind + 1, j, true, s,dp);
            int rF = f(ind + 1, j, false, s,dp);

            if (s[ind] == '&') {
                if (isTrue) ways += (lT * rT);
                else ways += (lT * rF + lF * rT + lF * rF);
            } 
            else if (s[ind] == '|') {
                if (isTrue) ways += (lT * rT + lT * rF + lF * rT);
                else ways += (lF * rF);
            } 
            else if (s[ind] == '^') {
                if (isTrue) ways += (lT * rF + lF * rT);
                else ways += (lT * rT + lF * rF);
            }
        }

        return dp[i][j][isTrue] = ways;
    }

  public:
    int countWays(string &s) {
        // code here
        int n = s.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(2,-1)));
        
        return  f(0,n-1,true,s,dp);
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        int ans = ob.countWays(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
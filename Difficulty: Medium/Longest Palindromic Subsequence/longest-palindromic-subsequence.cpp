//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution{
  public:
    int longestPalinSubseq(string s) {
        // DP : Mother Problem : Longest common subsequence
        // Variation - Here first string in s itselt
        // and another string is the reverse of s
        // i.e., Answer = |LCS(s, reverse(s))|
        
        string str1 = s;
        reverse(s.begin(), s.end()); // reverse the string s
        string str2 = s;
        
        int m = str1.size();
        int n = str2.size();
        
        int dp[m+1][n+1];
        
        for(int i=0; i<=m; i++) {
            for(int j=0; j<=n; j++) {
                if(i == 0 || j == 0) // initialization
                    dp[i][j] = 0;
                    
                // main logic here
                else if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else 
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        
        return dp[m][n];
    }
};



//{ Driver Code Starts.

int32_t main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
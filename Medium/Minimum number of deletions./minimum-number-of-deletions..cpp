//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
int minDeletions(string str, int n);

int main(){
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        string s;
        cin >> s;
        cout << minDeletions(s, n) << endl;

    }
return 0;
}
// } Driver Code Ends


int minDeletions(string s, int n) { 
    // DP : Mother Problem : Longest common subsequence
    // Variation - Here first string in s itselt
    // and another string is the reverse of s
    // Answer = |s| - |LCS(s, reverse(s))|

    string str1 = s;
    reverse(s.begin(), s.end()); // reverse the string s
    string str2 = s;

    int dp[n+1][n+1];

    for(int i=0; i<=n; i++) {
        for(int j=0; j<=n; j++) {
            if(i == 0 || j == 0) // initialization
                dp[i][j] = 0;

            // main logic
            else if(str1[i-1] == str2[j-1])
                dp[i][j] = 1 + dp[i-1][j-1];
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return n - dp[n][n];
} 
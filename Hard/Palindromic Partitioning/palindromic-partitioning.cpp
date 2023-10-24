//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    bool generate(string& s, vector<vector<bool>>& pal) {
        int n = s.size();
        
        for(int i=0; i<n; i++) {
            pal[i][i] = true;
        }
        
        for(int len=2; len<=n; len++) {
            for(int i=0; i<=n-len; i++) {
                int j = i+len-1;
                
                if(s[i]==s[j] && (len==2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                }
            }
        }
    }
    
    int palindromicPartition(string s)
    {
        // code here
        if(s.empty())
            return 0;
        
        int n = s.size();
        
        vector<vector<bool>> pal(n, vector<bool>(n, false));
        
        generate(s, pal);
        
        vector<int> dp(n, INT_MAX);
        dp[0] = 0;
        
        for(int i=0; i<n; i++) {
            if(pal[0][i])
                dp[i] = 0;
            else {
                for(int j=i; j>=1; j--) {
                    if(pal[j][i]) {
                        if(dp[j-1]+1 < dp[i])
                            dp[i] = dp[j-1]+1;
                    }
                }
            }
        }
        return dp[n-1];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends
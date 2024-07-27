//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
    int dp[501][501];
    
    int countMin(string str) {
        memset(dp, 0, sizeof(dp));
        return solve(str, 0, str.size() - 1);
    }
    
  private:
    int solve(string str, int l, int h) {
        if(l > h)   return INT_MAX;
        if(l == h)  return 0;
        if(l == h-1)    return str[l] == str[h] ? 0 : 1;
        
        if(dp[l][h])    return dp[l][h];
        
        return dp[l][h] = str[l] == str[h] ?
                            solve(str, l+1, h-1) :
                            min(solve(str, l, h-1), solve(str, l+1, h)) + 1;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}


// } Driver Code Ends
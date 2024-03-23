//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
private:
    bool isPalindrom(string str, int i, int j) {
        while(i < j) {
            if(str[i] != str[j])
                return false;
            i++;
            j--;
        }
        
        return true;
    }
    
public:
    // Approch 1: Only Recursion -> Result: TLE
    // int solve(string str, int i, int j) {
    //     // base condition
    //     if(i >= j)  return 0;
    //     // if the string is already a palindrom, no partitioning needed
    //     if(isPalindrom(str, i, j))    return 0;
        
    //     // next logic
    //     int ans = INT_MAX;
    //     for(int k=i; k<=j-1; k++) {
    //         int tempAns = solve(str, i, k) + solve(str, k+1, j) + 1;
    //         ans = min(ans, tempAns);
    //     }
        
    //     return ans;
    // }
    
    // Approch 2: Memoized Recursion -> Result: TLE
    // int dp[501][501];
    // int solve(string str, int i, int j) {
    //     // base condition
    //     if(i >= j)  return 0;
    //     // if the string is already a palindrom, no partitioning needed
    //     if(isPalindrom(str, i, j))    return 0;
        
    //     // if the current sub-problem is already solved
    //     if(dp[i][j] != -1)  return dp[i][j];
        
    //     // next logic
    //     int ans = INT_MAX;
    //     for(int k=i; k<=j-1; k++) {
    //         int tempAns = solve(str, i, k) + solve(str, k+1, j) + 1;
    //         ans = min(ans, tempAns);
    //     }
        
    //     // store the result, then return 
    //     return dp[i][j] = ans;
    // }
    
    // Approch 3: Memoized Recursion with more optimization -> Result: Accepted
    int dp[501][501];
    int solve(string str, int i, int j) {
        // base condition
        if(i >= j)  return 0;
        // if the string is already a palindrom, no partitioning needed
        if(isPalindrom(str, i, j))    return 0;
        
        // if the current sub-problem is already solved
        if(dp[i][j] != -1)  return dp[i][j];
        
        // next logic
        int ans = INT_MAX;
        for(int k=i; k<=j-1; k++) {
            int leftAns, rightAns;
            
            if(dp[i][k] != -1)
                leftAns = dp[i][k];
            else {
                leftAns = dp[i][k] = solve(str, i, k);
            }
            
            if(dp[k+1][j] != -1)
                rightAns = dp[k+1][j];
            else {
                rightAns = dp[k+1][j] = solve(str, k+1, j);
            }
            
            int tempAns = leftAns + rightAns + 1;
            ans = min(ans, tempAns);
        }
        
        // store the result, then return 
        return dp[i][j] = ans;
    }
    
    int palindromicPartition(string str) {
        // initializing dp array
        memset(dp, -1, sizeof(dp));
        
        // function call
        return solve(str, 0, str.size()-1);
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
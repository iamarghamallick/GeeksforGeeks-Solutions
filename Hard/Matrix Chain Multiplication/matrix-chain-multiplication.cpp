//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // Approch 1: Only recursive, Result: Time Limit Exceeded
    // int solve(int arr[], int i, int j) {
    //     // base case
    //     if(i >= j)  return 0;
        
    //     // next logic
    //     int ans = INT_MAX;
    //     for(int k=i; k<j; k++) {
    //         int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
    //         ans = min(ans, tempAns);
    //     }
        
    //     return ans;
    // }
    
    // Approch 2: Recursion with memoization
    int dp[101][101];
    
    int solve(int arr[], int i, int j) {
        // base case
        if(i >= j)  return 0;
        
        // next logic
        int ans = INT_MAX;
        
        // if the current sub-problem is already solved before
        if(dp[i][j] != -1)  return dp[i][j];
        
        // otherwise
        for(int k=i; k<j; k++) {
            int tempAns = solve(arr, i, k) + solve(arr, k+1, j) + (arr[i-1] * arr[k] * arr[j]);
            ans = min(ans, tempAns);
        }
        
        // store the current result into dp[][] table, then return
        return dp[i][j] = ans;
    }
    
    int matrixMultiplication(int N, int arr[]) {
        // initialize the globally declared dp[][] table with value -1
        memset(dp, -1, sizeof(dp));
        
        // choosing the i-th index and j-th index : i = 1 and j = N-1 (at the initial)
        return solve(arr, 1, N-1);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends
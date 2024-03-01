//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int solve(int arr[], int sum, int n, int** dp) {
        // base cases
        if(sum == 0)    return 1;
        if(n < 0)  return 0;

        if(dp[n][sum] != -1)
            return dp[n][sum];

        if(arr[n] > sum) {
            dp[n][sum] = solve(arr, sum, n-1, dp);
            return dp[n][sum];
        }

        dp[n][sum] = solve(arr, sum - arr[n], n-1, dp) || solve(arr, sum, n-1, dp);

        return dp[n][sum];
    }
    
    int equalPartition(int n, int arr[]) {
        // code here
        int sum = 0;
        for(int i=0; i<n; i++)
            sum += arr[i];
            
        // if sum is an odd number, impossible to do equal partion
        if(sum % 2 != 0)    return 0;
        
        // otherwise we try to find a subset of total sum / 2
        // subset sum problem
        
        // initializing the dp array
        int** dp;
        dp = new int*[n];

        for(int i=0; i<n; i++)
            dp[i] = new int[sum/2 + 1];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < sum/2 + 1; j++) 
                dp[i][j] = -1;
        
        return solve(arr, sum/2, n-1, dp);
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
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends
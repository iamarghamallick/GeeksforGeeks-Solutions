//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int solve(vector<int> arr, int sum, int n, int** dp) {
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

    bool isSubsetSum(vector<int>arr, int sum){
        // code here 
        int n = arr.size();
        
        int** dp;
        dp = new int*[n];

        for(int i=0; i<n; i++)
            dp[i] = new int[sum+1];

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < sum + 1; j++) 
                dp[i][j] = -1;
        
        return solve(arr, sum, n-1, dp);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, sum;
        cin >> N;
        vector<int> arr(N);
        for(int i = 0; i < N; i++){
            cin >> arr[i];
        }
        cin >> sum;
        
        Solution ob;
        cout << ob.isSubsetSum(arr, sum) << endl;
    }
    return 0; 
} 

// } Driver Code Ends
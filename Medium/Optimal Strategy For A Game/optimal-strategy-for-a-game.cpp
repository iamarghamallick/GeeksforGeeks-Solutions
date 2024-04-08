//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution {
    public:
    
    int dp[1001][1001];
    
    long long solve(int arr[], int n, int i, int j) {
        if ((i > j) || (i >= n) || (j < 0))
            return 0;
            
        if (dp[i][j] != 0)
            return dp[i][j];
            
        // if the user chooses ith coin, the opponent can choose
        // from i+1th or jth coin. if he chooses i+1th coin,
        // user is left with [i+2,j] range. if opp chooses jth
        // coin, then user is left with [i+1,j-1] range to
        // choose from. Also opponent tries to choose in such a
        // way that the user has minimum value left.
        long long option1 = arr[i] + min(solve(arr, n, i + 2, j), solve(arr, n, i + 1, j - 1));
        
        // if user chooses jth coin, opponent can choose ith
        // coin or j-1th coin. if opp chooses ith coin,user can
        // choose in range [i+1,j-1]. if opp chooses j-1th coin,
        // user can choose in range [i,j-2].
        long long option2 = arr[j] + min(solve(arr, n, i + 1, j - 1), solve(arr, n, i, j - 2));
        
        return dp[i][j] = max(option1, option2);
    }
    
    long long maximumAmount(int n, int arr[]) {
        memset(dp, 0, sizeof(dp));
        
        return solve(arr, n, 0, n-1);
    }
};

//{ Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends
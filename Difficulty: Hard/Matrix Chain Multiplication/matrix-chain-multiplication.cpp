//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int dp[101][101];
    
    int solve(vector<int> &arr, int i, int j) {
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
    
    int matrixMultiplication(vector<int> &arr) {
        // initialize the globally declared dp[][] table with value -1
        memset(dp, -1, sizeof(dp));
        
        // choosing the i-th index and j-th index : i = 1 and j = N-1 (at the initial)
        return solve(arr, 1, arr.size() - 1);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // to ignore the newline after the integer input
    while (t--) {
        int n;
        vector<int> a;
        string input;

        // Input format: first number n followed by the array elements
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.matrixMultiplication(a) << endl << "~\n";
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int dp[1001][1001];
    
    int solve(int i, vector<int>& wt, vector<int>& val, int W) {
        if(i >= wt.size())  return 0;
        
        if(dp[i][W])    return dp[i][W];
        
        if(wt[i] <= W) {
            int take = val[i] + solve(i+1, wt, val, W - wt[i]);
            int notTake = solve(i+1, wt, val, W);
            return dp[i][W] = max(take, notTake);
        }
        
        return dp[i][W] = solve(i+1, wt, val, W);
    }
    
    // Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        memset(dp, 0, sizeof(dp));
        return solve(0, wt, val, W);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends
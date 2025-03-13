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
    int knapsack(int W, vector<int>& val, vector<int>& wt) {
        memset(dp, 0, sizeof(dp));
        return solve(0, wt, val, W);
    }
};



//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapsack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
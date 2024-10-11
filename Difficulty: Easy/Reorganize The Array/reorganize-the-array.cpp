//{ Driver Code Starts
#include <bits/stdc++.h>
#include <iostream>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> rearrange(const vector<int>& arr) {
        vector<int> ans(arr.size(), -1);
        for(int i=0; i<arr.size(); i++) 
            if(arr[i] != -1) 
                ans[arr[i]] = arr[i];
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> arr;
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution solution;
        vector<int> ans = solution.rearrange(arr);

        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends
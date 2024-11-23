//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int getMinDiff(int k, vector<int> &arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minHeight = arr[0];
        int maxHeight = arr[n-1];
        int ans = maxHeight - minHeight;
        
        for(int i=1; i<n; i++) {
            minHeight = min(arr[0] + k, arr[i] - k);
            maxHeight = max(arr[i-1] + k, arr[n-1] - k);
            ans = min(ans, maxHeight - minHeight);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
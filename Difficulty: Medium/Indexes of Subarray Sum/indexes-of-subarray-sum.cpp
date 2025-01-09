//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        unordered_map<int, pair<int,int>> mp;
        int n = arr.size();
        
        vector<int> pref(n, 0);
        pref[0] = arr[0];
        
        for (int i=1; i<n; i++) {
            pref[i] = pref[i-1] + arr[i];
        }
        
        for (int i=0; i<n; i++) {
            if (pref[i] == target) {
                return {1, i+1};
            }
            
            if (mp.find(pref[i] - target) != mp.end()) {
                return {mp[pref[i]-target].second+1, i+1};
            }
            
            mp[pref[i]].first++;
            mp[pref[i]].second = i+1;
        }
        
        return {-1};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends
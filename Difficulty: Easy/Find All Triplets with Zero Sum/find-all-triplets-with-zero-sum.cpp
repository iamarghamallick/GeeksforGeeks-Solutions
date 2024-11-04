//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        int n = arr.size();
        set<vector<int>> res;
        unordered_map<int, vector<pair<int, int>>> map;
        
        for(int i=0; i<n; i++) 
            for(int j=i+1; j<n; j++) 
                map[arr[i] + arr[j]].push_back({i, j});

        for(int i=0; i<n; i++) {
            int rem = -arr[i];
            if(map.find(rem) != map.end()) {
                vector<pair<int, int>> v = map[rem];
                for(auto p : v) {
                    if(p.first != i && p.second != i) {
                        vector<int> curr = { p.first, p.second, i };
                        sort(curr.begin(), curr.end());
                        res.insert(curr);
                    }
                }
            }
        }
        
        vector<vector<int>> ans(res.begin(), res.end());
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        unordered_map<int, int> mapStart, mapEnd;
        for(int num : arr) {
            mapStart[num] = INT_MAX;
            mapEnd[num] = INT_MIN;
        }
        for(int i=0; i<arr.size(); i++) {
            mapStart[arr[i]] = min(mapStart[arr[i]], i);
            mapEnd[arr[i]] = max(mapEnd[arr[i]], i);
        }
        int ans = 0;
        for(int num : arr) {
            ans = max(ans, mapEnd[num] - mapStart[num]);
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
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends
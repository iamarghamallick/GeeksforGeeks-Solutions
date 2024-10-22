//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int sameOccurrence(vector<int>& arr, int x, int y) {
        int n = arr.size();
        vector<int> countX(n, 0), countY(n, 0), diff(n);
        if(arr[0] == x) countX[0] = 1;
        if(arr[0] == y) countY[0] = 1;
        diff[0] = countX[0] - countY[0];
        for(int i=1; i<n; i++) {
            if(arr[i] == x) countX[i] = countX[i-1] + 1;
            else countX[i] = countX[i-1];
            if(arr[i] == y) countY[i] = countY[i-1] + 1;
            else countY[i] = countY[i-1];
            diff[i] = countX[i] - countY[i];
        }
        map<int, int> map;
        for(int num : diff) map[num]++;
        int result = map[0];
        for (auto it = map.begin(); it != map.end(); it++) 
            result = result + ((it->second) * ((it->second) - 1)) / 2;
        return result;
    }
};

//{ Driver Code Starts.
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {

        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        string ks;
        getline(cin, ks);
        int x = stoi(ks);
        string ks1;
        getline(cin, ks1);
        int y = stoi(ks1);
        Solution ob;
        int ans = ob.sameOccurrence(arr, x, y);
        cout << ans << "\n";
        // cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends
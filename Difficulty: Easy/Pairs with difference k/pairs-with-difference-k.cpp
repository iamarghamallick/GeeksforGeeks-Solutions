//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    /* Returns count of pairs with difference k  */
    int countPairsWithDiffK(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int, int> map;
        int count = 0;
        for(int i=0; i<n; i++) {
            if(map.find(arr[i] + k) != map.end())   count += map[arr[i] + k];
            if(map.find(arr[i] - k) != map.end())   count += map[arr[i] - k];
            map[arr[i]]++;
        }

        return count;
    }
    
    // int countPairsWithDiffK(vector<int>& arr, int k) {
    //     int n = arr.size();
    //     int count = 0;
    //     for(int i=0; i<n; i++) 
    //         for(int j=i+1; j<n; j++) 
    //             if(abs(arr[i] - arr[j]) == k)
    //                 count++;

    //     return count;
    // }
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
        int k = stoi(ks);
        Solution ob;
        auto ans = ob.countPairsWithDiffK(arr, k);
        cout << ans << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
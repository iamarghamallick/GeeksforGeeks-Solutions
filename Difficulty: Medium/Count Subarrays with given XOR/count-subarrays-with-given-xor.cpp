//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        int n = arr.size();
        vector<int> pref(n, 0);
        pref[0] = arr[0];
        
        for(int i=1; i<n; i++) {
            pref[i] = pref[i-1] xor arr[i];
        }
        
        unordered_map<int, int> mp;
        int cnt = 0;
        
        for(int i=0; i<n; i++) {
            if (pref[i] == k) cnt++;
            
            if (mp.find(pref[i] xor k) != mp.end()) {
                cnt += mp[pref[i] xor k];
            }
            
            mp[pref[i]]++;
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore(); // Ignore the newline after the number of test cases

    while (tc-- > 0) {
        string input;
        getline(cin, input); // Read the whole line for the array

        stringstream ss(input);
        vector<int> arr;
        int num;

        while (ss >> num) {
            arr.push_back(num); // Push numbers into the vector
        }

        int k;
        cin >> k;
        cin.ignore(); // Ignore the newline after k

        Solution obj;
        cout << obj.subarrayXor(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:

    string longestCommonPrefix(vector<string> arr) {
        string ans = "";
        int n = arr.size(), index = 0, len = INT_MAX;
        
        for(int i=0; i<n; i++)
            len = min(len, (int)arr[i].size());
            
        while(index < len) {
            char c = arr[0][index];
            bool flag = true;
            for(int i=1; i<n; i++) {
                if(arr[i][index] != c) {
                    flag = false;
                    break;
                }
            }
            if(flag)    ans += c;
            else        break;
            index++;
        }
        
        return ans == "" ? "-1" : ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.longestCommonPrefix(arr) << endl;
    }
}

// } Driver Code Ends
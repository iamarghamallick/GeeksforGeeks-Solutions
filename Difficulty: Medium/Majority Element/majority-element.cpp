//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int majorityElement(vector<int>& arr) {
        int n = arr.size(), candidate = -1, count = 0;
        for(int i=0; i<n; i++) {
            if(count == 0) {
                candidate = arr[i];
                count = 1;
            } else if(arr[i] == candidate) {
                count++;
            } else {
                count--;
            }
        }
        
        count = 0;
        for(int i=0; i<n; i++) {
            if(arr[i] == candidate)
                count++;
        }
        
        return count > n / 2 ? candidate : -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            a.push_back(num);

        Solution obj;
        cout << obj.majorityElement(a) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
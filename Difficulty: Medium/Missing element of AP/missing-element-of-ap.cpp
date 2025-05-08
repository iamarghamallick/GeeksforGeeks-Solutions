//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  public:
    int findMissing(vector<int> &arr) {
        int n = arr.size();
        int d = min(arr[n - 1] - arr[n - 2] , arr[1] - arr[0]);
        int s = 0; 
        int e = n;
        int ans = 0;
        while(s <= e){
            int mid = s + (e-s)/2;
            int val = arr[0] + mid * d;
            if(arr[mid] == val) {
                ans = val;
                s = mid + 1;
            } 
            else e = mid - 1;
        }
        
        return ans + d;
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
        cout << ob.findMissing(arr) << "\n";
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
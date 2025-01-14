//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    int findEquilibrium(vector<int> &arr) {
        int n=arr.size();
        vector<int>pre(n, 0), suf(n, 0);
        
        int sum=0;
        for(int i=0; i<n; i++){
            pre[i]=sum;
            sum+=arr[i];
        }
        sum=0;
        for(int i=n-1; i>=0; i--){
            suf[i]=sum;
            sum+=arr[i];
        }
        
        for(int i=0; i<n; i++){
            if(pre[i]==suf[i]) return i;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<int> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.findEquilibrium(arr) << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends
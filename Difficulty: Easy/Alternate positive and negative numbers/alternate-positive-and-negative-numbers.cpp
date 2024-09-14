//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    void rearrange(vector<int> &arr) {
        vector<int> pos, neg;
        for(int num : arr) {
            if(num >= 0)    pos.push_back(num);
            else neg.push_back(num);
        }
        
        int posIdx = 0, negIdx = 0;
        for(int i=0; i<arr.size(); i++) {
            if(i % 2 == 0)  arr[i] = posIdx < pos.size() ? pos[posIdx++] : neg[negIdx++];
            else    arr[i] = negIdx < neg.size() ? neg[negIdx++] : pos[posIdx++];
        }
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution ob;
        ob.rearrange(arr);
        for (int i = 0; i < arr.size(); i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
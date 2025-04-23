//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> singleNum(vector<int>& nums) {
        int xorOfAll = 0;
        for(int num : nums) xorOfAll ^= num;
        int number = xorOfAll & -xorOfAll;
        int x = 0, y = 0;
        for(int num : nums) {
            if(num & number)    x ^= num;
            else    y ^= num;
        }
        nums.clear();
        if(x > y) {
            nums.push_back(y);
            nums.push_back(x);
        } else {
            nums.push_back(x);
            nums.push_back(y);
        }
        return nums;
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

        Solution ob;
        vector<int> ans = ob.singleNum(arr);
        for (auto it : ans) {
            cout << it << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
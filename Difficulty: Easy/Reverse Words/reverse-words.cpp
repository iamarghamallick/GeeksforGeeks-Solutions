//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        string ans = "";
        string temp = "";
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '.') {
                ans = str[i] + temp + ans;
                temp = "";
            } else {
                temp += str[i];
            }
        }
        ans = temp + ans;
        return ans.substr(0);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends
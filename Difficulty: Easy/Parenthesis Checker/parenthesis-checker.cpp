//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isBalanced(string& s) {
        stack<char> st;
        unordered_map<char, char> map;
        map[')'] = '('; map['}'] = '{'; map[']'] = '[';
        int i = 0;
        while(i < s.size()) {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[') 
                st.push(s[i]);
            else if(!st.empty() && st.top() == map[s[i]]) {
                st.pop();
            } else {
                return false;
            }
            i++;
        }
        
        return st.empty();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    string a;
    cin >> t;
    while (t--) {
        cin >> a;
        Solution obj;
        if (obj.isBalanced(a))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}
// } Driver Code Ends
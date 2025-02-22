//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& str) {
        stack<int> st;
        int maxLen = 0;
        st.push(-1);
        
        for(int i=0; i<str.size(); i++) {
            if(str[i] == '(')
                st.push(i);
            else {
                st.pop();
                
                if(st.empty())
                    st.push(i);
                else
                    maxLen = max(maxLen, i - st.top());
            }
        }
        
        return maxLen;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
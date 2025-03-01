//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    string decodedString(string &s) {
        int n = s.length();
        if(n == 0) return s; // If the string is empty, return it as is.

        stack<int> st; // Stack to store the numbers (repetition counts).
        stack<string> str; // Stack to store the strings.
        string temp = ""; // Temporary string to build the current string.
        int num = 0; // Temporary variable to build the current number.

        for(int i = 0; i < n; i++) {
            if(isdigit(s[i])) {
                // If the character is a digit, build the number.
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                // If we encounter an opening bracket, push the current number and string onto the stacks.
                st.push(num);
                num = 0; // Reset the number.
                str.push(temp);
                temp = ""; // Reset the string.
            }
            else if(s[i] == ']') {
                // If we encounter a closing bracket, pop the number and repeat the current string.
                int k = st.top();
                st.pop();
                string currentString = str.top();
                str.pop();
                for(int j = 1; j <= k; j++) {
                    currentString += temp; // Repeat the string k times.
                }
                temp = currentString; // Update the current string.
            }
            else {
                // If it's a character, append it to the current string.
                temp += s[i];
            }
        }
        return temp; // Return the decoded string.
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.decodedString(s) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
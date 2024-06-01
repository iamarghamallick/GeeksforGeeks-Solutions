//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        int x = 0, y = 0;
        vector<int> chars(26, 0);
        
        for(int i=0; i<s.size(); i++)
            chars[s[i] - 'a']++;
        
        for(int i=0; i<26; i++) {
            if(chars[i] > 0 && i % 2 == 0 && chars[i] % 2 == 1)
                x++;
            if(chars[i] > 0 && i % 2 == 1 && chars[i] % 2 == 0)
                y++;
        }
        
        return (x + y) % 2 == 0 ? "EVEN" : "ODD";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends
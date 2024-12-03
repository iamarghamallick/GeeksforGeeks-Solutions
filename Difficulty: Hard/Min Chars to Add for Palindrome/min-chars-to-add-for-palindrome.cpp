//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> computeLPSArray(string &pat) {
        int n = pat.length();
        vector<int> lps(n);
    
        // lps[0] is always 0
        lps[0] = 0;
        int len = 0;
    
        // loop calculates lps[i] for i = 1 to M-1
        int i = 1;
        while (i < n) {
    
            // If the characters match, increment len
            // and set lps[i]
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
    
            // If there is a mismatch
            else if (pat[i] != pat[len]) {
    
                // If len is not zero, update len to
                // the last known prefix length
                if (len != 0) {
                    len = lps[len - 1];
                }
    
                // No prefix matches, set lps[i] to 0
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int minChar(string& s) {
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
    
        // Get concatenation of string, special character
        // and reverse string
        s = s + "$" + rev;
    
        //  Get LPS array of this concatenated string
        vector<int> lps = computeLPSArray(s);
    
        // By subtracting last entry of lps vector from
        // string length, we will get our result
        return (n - lps.back());
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
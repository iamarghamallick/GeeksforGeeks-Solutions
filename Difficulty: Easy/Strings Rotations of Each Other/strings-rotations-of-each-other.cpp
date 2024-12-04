//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> computeLPSArray(string& pat) {
         int n = pat.size();
         vector<int> lps(n);
      
        // Length of the previous longest prefix suffix
        int len = 0;
    
        // lps[0] is always 0
        lps[0] = 0;
    
        // loop calculates lps[i] for i = 1 to n-1
        int i = 1;
        while (i < n) {
            // If the characters match, increment len 
            // and extend the matching prefix
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
          
            // If there is a mismatch
            else {
              
                // If len is not zero, update len to
                // last known prefix length
                if (len != 0) {
                    len = lps[len - 1];
                }
              
                // No prefix matches, set lps[i] = 0
                // and move to the next character
                else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        return lps;
    }

    // Function to check if two strings are rotations of each other or not.
    bool areRotations(string &s1, string &s2) {
        string txt = s1 + s1;
        string pat = s2;
          
        // search the pattern string s2 in the concatenation string 
        int n = txt.length();
        int m = pat.length();
    
        // Create lps[] that will hold the longest prefix suffix
        // values for pattern
        vector<int> lps = computeLPSArray(pat);
      
        int i = 0; 
        int j = 0;
        while (i < n) {
            if (pat[j] == txt[i]) {
                j++;
                i++;
            }
    
            if (j == m) {
                return true;
            }
    
            // Mismatch after j matches
            else if (i < n && pat[j] != txt[i]) {
    
                // Do not match lps[0..lps[j-1]] characters,
                // they will match anyway
                if (j != 0)
                    j = lps[j - 1];
                else
                    i = i + 1;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1;
        string s2;
        cin >> s1 >> s2;
        Solution sol;
        int result = sol.areRotations(s1, s2);
        if (result) {
            cout << "true" << endl;

        } else {
            cout << "false" << endl;
        }
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
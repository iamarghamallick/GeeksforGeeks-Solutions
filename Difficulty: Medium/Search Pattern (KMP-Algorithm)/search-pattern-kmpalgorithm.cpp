//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
      void constructLps(string &pat, vector<int> &lps) {
        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;
    
        // lps[0] is always 0
        lps[0] = 0;
    
        int i = 1;
        while (i < pat.length()) {
    
            // If characters match, increment the size of lps
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            }
    
            // If there is a mismatch
            else {
                if (len != 0) {
    
                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                }
                else {
    
                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
    }

    vector<int> search(string& pat, string& txt) {
        // int n = txt.size();
        // int left = 0, right = pat.size() - 1;
        // vector<int> ans;
        // while(right < n) {
        //     if(txt.substr(left, pat.size()) == pat)
        //         ans.push_back(left);
        //     left++; right++;
        // }
        // return ans;
        
        int n = txt.length();
        int m = pat.length();
    
        vector<int> lps(m);
        vector<int> res;
    
        constructLps(pat, lps);
    
        // Pointers i and j, for traversing
        // the text and pattern
        int i = 0;
        int j = 0;
    
        while (i < n) {
    
            // If characters match, move both pointers forward
            if (txt[i] == pat[j]) {
                i++;
                j++;
    
                // If the entire pattern is matched
                // store the start index in result
                if (j == m) {
                    res.push_back(i - j);
    
                    // Use LPS of previous index to
                    // skip unnecessary comparisons
                    j = lps[j - 1];
                }
            }
    
            // If there is a mismatch
            else {
    
                // Use lps value of previous index
                // to avoid redundant comparisons
                if (j != 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << "[]" << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends
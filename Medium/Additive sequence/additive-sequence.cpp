//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    bool isAdditiveSequence(string s) {
        int n = s.size();
        int a = 0;
        for(int i=0; i<n/2; i++) {
            a = a * 10 + (s[i] - '0');
            
            int b = 0;
            for(int j=i+1; j<n-1; j++) {
                b = b * 10 + (s[j] - '0');
                
                int c = 0;
                int k = j+1;
                for(; k<n; k++) {
                    c = c * 10 + (s[k] - '0');
                    
                    if(c == (a + b)) {
                        a = b;
                        b = c;
                        c = 0;
                    }
                }
                
                if(k == n && c == 0)
                    return 1;
            }
        }
        
        return 0;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;

    Solution sol;

    while (t--) {
        string s;
        cin >> s;

        bool result = sol.isAdditiveSequence(s);
        cout << result << endl;
    }

    return 0;
}

// } Driver Code Ends
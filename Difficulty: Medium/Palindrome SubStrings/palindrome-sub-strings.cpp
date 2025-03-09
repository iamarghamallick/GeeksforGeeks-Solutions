//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        int n = s.size();
        int ans = 0;

        for(int mid=0; mid<n; mid++) {
            int count = 1;
            for(int i=1; i<n-mid && mid-i>=0; i++) {
                if(s[mid-i] == s[mid+i])
                    count += 1;
                else
                    break;
            }
            
            ans += count;
            count = 0;

            for(int i=0; i<n-mid-1 && mid-i>=0; i++) {
                if(s[mid-i] == s[mid+i+1])
                    count += 1;
                else
                    break;
            }
            ans += count;
        }
        
        return ans-n;
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
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int findSubString(string& str) {
        int n = str.size();
        vector<bool> visited(26, false);
        int distinct = 0;
        for(char c : str) {
            if(visited[c - 'a'] == false) {
                visited[c - 'a'] = true;
                distinct++;
            }
        }
        
        vector<int> curr(26, 0);
        int count = 0;
        int ans = n;
        int start = 0;
        for(int end = 0; end < n; end++) {
            curr[str[end] - 'a']++;
            if(curr[str[end] - 'a'] == 1) {
                count++;
            }
            
            while(count == distinct) {
                ans = min(ans, end - start + 1);
                
                curr[str[start] - 'a']--;
                if(curr[str[start] - 'a'] == 0) {
                    count--;
                }
                start++;
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.
//      Driver code
int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
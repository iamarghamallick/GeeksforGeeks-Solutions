//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int n = str.size(), space = 0;
        if(n < 26)  return false;
        vector<bool> arr(26, false);
        for(int i=0; i<n; i++) {
            if(str[i] == ' ')   space++;
            else    arr[str[i] - 'a'] = true;
        }
        int count = 0;
        for(int i=0; i<26; i++)
            if(arr[i])
                count++;
        int nonSpace = n - space;
        int avail = nonSpace - count;
        
        return (26 - count) <= min(avail, k);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
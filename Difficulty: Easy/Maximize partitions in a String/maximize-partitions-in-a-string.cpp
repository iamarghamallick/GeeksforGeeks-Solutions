//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxPartitions(string &s) {
        map<char,int>mp; 
        for(int i=0; i<s.length(); i++)
            mp[s[i]] = i;

        int i=0, cnt=0;
        while(i<s.length()){
           int j=i;
           int idx=mp[s[j]];
           while(j<idx){
               idx=max(idx,mp[s[j]]);
               j++;
           }
           i=idx+1;
           cnt++;
        }
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;

    for (int i = 0; i < tc; ++i) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.maxPartitions(s) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends
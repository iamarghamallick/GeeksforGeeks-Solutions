//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
    int wordBreak(int n, string A, vector<string> &B) {
        //code here
        int i, j, k;
        unordered_set<string> us;
        for (i = 0; i < n; i++)
            us.insert(B[i]);
        int len = (int)A.size();
        vector<bool> dp(len + 1, false);
        dp[0] = true;
        for (int i = 1; i <= len; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (dp[j] && us.find(A.substr(j, i - j)) != us.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[len];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends
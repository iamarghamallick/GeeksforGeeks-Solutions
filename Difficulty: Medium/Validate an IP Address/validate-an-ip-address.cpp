//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        vector<string> parts;
        int i = 0;
        int n = str.length();
        while(i<n) {
            string st;
            while(i<n && str[i]!='.'){
                st+=str[i];
                i++;
            }
            parts.push_back(st);
            i++;
        }
        if(parts.size() != 4)
            return false;
        
        for(auto it : parts){
            if(it.length()>3 || it.length()==0)
                return false;
                
            int octal = 0;
            for(auto its : it)
                octal = octal*10+(its-'0');
            if(octal<0 || octal>255)
                return false;
            if(octal>=0 && octal<=9 && it.length()>1)
                return false;
            if(octal>=10 && octal<=99 && it.length()>2)
                return false;
        }
        
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends
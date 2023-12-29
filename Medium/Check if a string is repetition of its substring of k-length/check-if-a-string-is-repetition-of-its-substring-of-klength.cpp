//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:
	
	int kSubstrConcat (int n, string s, int k) {
	    // Your Code Here
	    if(n%k != 0) return 0;
	    
        unordered_map<string, int> m;
        int i = 0;
        
        while(i < s.size()) {
            string temp;
            int x = k;
            while(x-- && i<n) 
                temp+=s[i++];
            m[temp]++;
        }
        
        if(m.size() > 2) return 0;
        if(m.size() == 1) return 1;
        
        int mn = n;
        for(auto i: m)
            mn = min(i.second, mn);
            
        return mn == 1;
	}
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
	{
		int n; cin >> n;
		string s; cin >> s;
		int k; cin >> k;
        Solution  ob;
		cout << ob.kSubstrConcat (n, s, k) << endl;
	}
}
// } Driver Code Ends
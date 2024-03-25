//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    vector<string> ans;
    
    void solve(string s, int extraOnes, int remainingPlaces) {
        // if number is generated
        if(remainingPlaces == 0) {
            ans.push_back(s);
            return;
        }
        
        // Append 1 at the current number and reduce
        // the remaining places by one
        solve(s + "1", extraOnes + 1, remainingPlaces - 1);
        
        // If more ones than zeros, append 0 to the
        // current number and reduce the remaining
        // places by one
        if(extraOnes > 0)
            solve(s + "0", extraOnes - 1, remainingPlaces - 1);
    }
    
	vector<string> NBitBinary(int n) {
	    solve("", 0, n);
	    return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends
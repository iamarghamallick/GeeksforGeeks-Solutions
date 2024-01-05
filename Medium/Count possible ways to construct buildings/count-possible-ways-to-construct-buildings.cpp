//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int TotalWays(int N) {
	    // Code here
	    long long int mod = 1e9 + 7;
        
        if(N==1) return 4;
        if(N==2) return 9;
        
        int prev_two = 2, prev_one = 3, curr = 0;
        
        for (int i = 3; i <= N; i++) {
            curr = (prev_one + prev_two + mod) % mod ;
            prev_two = prev_one ;
            prev_one = curr;
        }
        
        long long total = ((curr%mod) * (curr%mod)) % mod;
        
        return total;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
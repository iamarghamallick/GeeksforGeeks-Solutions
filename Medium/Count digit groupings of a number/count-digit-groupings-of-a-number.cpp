//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int solve(int ind, int sum, int n, string str, vector<vector<int>> &dp) { 
        if(ind >= n) return 1; 
      
        if(dp[ind][sum] != -1) return dp[ind][sum]; 
        int nsum = 0, ans = 0; 
      
        for(int i = ind; i < n; i++) { 
            nsum += (str[i]-'0'); 
            if(nsum >= sum) 
                ans += solve(i+1, nsum, n, str, dp); 
        }
        
        return dp[ind][sum] = ans; 
    } 
  
    int TotalCount(string str){  
        int n = str.length(); 
        vector<vector<int>> dp(n+1, vector<int> (915, -1)); 
      
        return solve(0, 0, n, str, dp); 
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution ob;
		int ans = ob.TotalCount(str);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    long countSubarrays(int a[], int n, int L, int R)
    {
        // Complete the function
        long ans = 0;
        long small = 0;
        long valid = 0;
        
        for(int i=0; i<n; i++) {
            if(a[i] < L) {
                ++valid;
                ++small;
            } else if(a[i] > R) {
                ans += (valid * (valid+1)) / 2;
                ans -= (small * (small+1)) / 2;
                
                // start a new sub-problem
                valid = small = 0;
            } else {
                ans -= (small * (small+1)) / 2;
                small = 0;
                ++valid;
            }
        }
        
        ans += (valid * (valid+1)) / 2;
        ans -= (small * (small+1)) / 2;
        
        return ans;
    }
};

//{ Driver Code Starts.
// driver program
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        
        int n ,l,r;
        cin >> n>>l>>r;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];
        Solution ob;
    	cout << ob.countSubarrays(a, n, l, r)<<endl;
    }
	return 0;
}

// } Driver Code Ends
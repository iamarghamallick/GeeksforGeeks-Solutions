//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
  public:
    int minDist(int a[], int n, int x, int y) {
        // code here
        int xIndex = -1;
        int yIndex = -1;
        int ans = INT_MAX;
        for(int i=0; i<n; i++) {
            if(a[i] == x)
                xIndex = i;
            if(a[i] == y)
                yIndex = i;
                
            if(xIndex != -1 && yIndex != -1)
                ans = min(ans, abs(xIndex-yIndex));
        }
        
        if(ans != INT_MAX)
            return ans;
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        int x, y;
        cin >> x >> y;
        Solution obj;
        cout << obj.minDist(a, n, x, y) << endl;
    }
    return 0;
}

// } Driver Code Ends
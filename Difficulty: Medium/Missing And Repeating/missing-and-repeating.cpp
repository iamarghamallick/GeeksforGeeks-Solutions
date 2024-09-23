//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> findTwoElement(vector<int>& a) {
        // int n = arr.size();
        // int s = (n * (n + 1)) / 2;
        // int ssq = (n * (n + 1) * (2 * n + 1)) / 6;
        
        // for(int &num : arr) {
        //     s -= num;
        //     ssq -= num * num;
        // }
        
        // int missing = (s + ssq / s) / 2;
        // int repeating = missing - s;
        
        // return { repeating, missing };
        
        // int n = arr.size();
        // long long missing = (n * (n + 1)) / 2;
        // long long repeating = 0;
    
        // for (int i=0; i<n; i++) {
        //     if (arr[abs(arr[i]) - 1] > 0) {
        //         arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        //         missing -= abs(arr[i]);
        //     }
        //     else
        //         repeating = abs(arr[i]);
        // }
        
        // return { repeating, missing };
        
        long long n = a.size(); // size of the array

        // Find Sn and S2n:
        long long SN = (n * (n + 1)) / 2;
        long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;
    
        // Calculate S and S2:
        long long S = 0, S2 = 0;
        for (int i = 0; i < n; i++) {
            S += a[i];
            S2 += (long long)a[i] * (long long)a[i];
        }
    
        //S-Sn = X-Y:
        long long val1 = S - SN;
    
        // S2-S2n = X^2-Y^2:
        long long val2 = S2 - S2N;
    
        //Find X+Y = (X^2-Y^2)/(X-Y):
        val2 = val2 / val1;
    
        //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
        // Here, X-Y = val1 and X+Y = val2:
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
    
        return {(int)x, (int)y};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minCandy(int n, vector<int> &rat) {
        // code here
        vector<int> arr(n, 1);
        
        for(int i=1; i<n; i++) {
            if(rat[i] > rat[i-1])   arr[i] = arr[i-1] + 1;
        }
        
        for(int i=n-2; i>=0; i--) {
            if(rat[i] > rat[i+1] && arr[i] <= arr[i+1])   arr[i] = arr[i+1] + 1;
        }
        
        int ans = 0;
        for(int i=0; i<n; i++)  ans += arr[i];
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        vector<int> ratings(N);
        for (int i = 0; i < N; i++) {
            cin >> ratings[i];
        }
        Solution obj;
        cout << obj.minCandy(N, ratings) << endl;
    }
    return 0;
}
// } Driver Code Ends
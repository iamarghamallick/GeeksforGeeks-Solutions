//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int low = 0;
        int high = arr.size() - 1;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(arr[mid] <= key)
                low = mid + 1;
            else 
                high = mid - 1;
        }
        // returns the index of the first element greater than 'key'
        return low;
    }
    
    vector<int> countElements(vector<int> &a, vector<int> &b, int n,
                              vector<int> &query, int q) {
        vector<int> ans;
        sort(b.begin(), b.end()); // sort b to use binary search
        
        for(int i=0; i<q; i++) {
            int idx = search(b, a[query[i]]);
            ans.push_back(idx);
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;

    cin >> t;

    while (t--) {

        int n;
        cin >> n;
        vector<int> a, b, ans;
        int input;
        for (int i = 0; i < n; i++) {
            cin >> input;
            a.push_back(input);
        }
        for (int i = 0; i < n; i++) {
            cin >> input;
            b.push_back(input);
        }
        int q;
        cin >> q;
        vector<int> query;
        for (int i = 0; i < q; i++) {
            cin >> input;
            query.push_back(input);
        }
        Solution obj;
        ans = obj.countElements(a, b, n, query, q);
        for (int i = 0; i < q; i++) {
            cout << ans[i] << endl;
        }
    }
    return 0;
}
// } Driver Code Ends
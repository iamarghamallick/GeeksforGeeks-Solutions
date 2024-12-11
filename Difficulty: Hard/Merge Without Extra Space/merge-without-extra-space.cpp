//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthSmallest(vector<int> &a, vector<int> &b, int k) {
        int n = a.size(), m = b.size();
        int lo = 0, hi = n, idx = 0;
        while (lo <= hi) {
            int mid1 = (lo + hi) / 2;
            int mid2 = k - mid1;
           
            // We don't have mid2 elements in b[], so pick more
            // elements from a[]
            if (mid2 > m) {
                lo = mid1 + 1;
                continue;
            }
    
            // Find elements to the left and right of partition in a[]
            int l1 = (mid1 == 0 ? INT_MIN : a[mid1 - 1]);
            int r1 = (mid1 == n ? INT_MAX : a[mid1]);
    
            // Find elements to the left and right of partition in b[]
            int l2 = (mid2 == 0 ? INT_MIN : b[mid2 - 1]);
            int r2 = (mid2 == m ? INT_MAX : b[mid2]);
    
            // If it is a valid partition
            if (l1 <= r2 && l2 <= r1) {
                idx = mid1;
                break;
            }
    
            // Check if we need to take lesser elements from a[]
            if (l1 > r2)
                hi = mid1 - 1;
    
            // Check if we need to take more elements from a[]
            else
                lo = mid1 + 1;
        }
        return idx;
    }

    void mergeArrays(vector<int>& a, vector<int>& b) {
        int n = a.size();
        int m = b.size();
        int idx = kthSmallest(a, b, n);
    
        // Move all smaller elements in a[]
        for (int i = idx; i < n; i++) {
            swap(a[i], b[i - idx]);
        }
    
        // Sort both a[] and b[]
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};

//{ Driver Code Starts.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t; // Inputting the test cases

    while (t--) {
        vector<int> a, b;

        // Reading the first array as a space-separated line
        string arr1;
        getline(cin >> ws, arr1); // Use ws to ignore any leading whitespace
        stringstream ss1(arr1);
        int num;
        while (ss1 >> num) {
            a.push_back(num);
        }

        // Reading the second array as a space-separated line
        string arr2;
        getline(cin, arr2);
        stringstream ss2(arr2);
        while (ss2 >> num) {
            b.push_back(num);
        }

        Solution ob;
        ob.mergeArrays(a, b);

        // Output the merged result
        for (int i = 0; i < a.size(); i++) {
            cout << a[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < b.size(); i++) {
            cout << b[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends
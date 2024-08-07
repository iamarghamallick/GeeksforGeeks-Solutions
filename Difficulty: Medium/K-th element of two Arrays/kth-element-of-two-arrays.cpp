//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size();
        int m = arr2.size();
        
        return solve(arr1, arr2, 0, 0, n-1, m-1, k-1);
    }
    
  private:
    int solve(vector<int> &arr1, vector<int> &arr2, int left1, int left2, int right1, int right2, int k) {
        // If arr1 is exhausted, return the k-th element from arr2
        if (left1 > right1)
            return arr2[left2 + k];
        // If arr2 is exhausted, return the k-th element from arr1
        if (left2 > right2)
            return arr1[left1 + k];
            
        int mid1 = (left1 + right1) / 2;
        int mid2 = (left2 + right2) / 2;
        
        // If the number of elements considered is less than k
        if ((mid1 - left1) + (mid2 - left2) < k) {
            if (arr1[mid1] > arr2[mid2])
                // Discard the left part of the second array
                return solve(arr1, arr2, left1, mid2 + 1, right1, right2, k - (mid2 - left2 + 1));
            else
                // Discard the left part of the first array
                return solve(arr1, arr2, mid1 + 1, left2, right1, right2, k - (mid1 - left1 + 1));

        } else {
            if (arr1[mid1] > arr2[mid2])
                // Discard the right part of the first array
                return solve(arr1, arr2, left1, left2, mid1 - 1, right2, k);
            else
                // Discard the right part of the second array
                return solve(arr1, arr2, left1, left2, right1, mid2 - 1, k);
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends
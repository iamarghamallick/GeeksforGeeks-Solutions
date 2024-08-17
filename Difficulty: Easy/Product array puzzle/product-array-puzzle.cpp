//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // nums: given vector
    // return the Product vector P that hold product except self at each index
    vector<long long int> productExceptSelf(vector<long long int>& nums) {
        int n = nums.size();
        if(n == 1)
            return {1};
        
        vector<long long int> left(n, nums[0]);
        vector<long long int> right(n, nums[n-1]);
        
        for(int i=1; i<n; i++)
            left[i] = left[i-1] * nums[i];
        for(int i=n-2; i>=0; i--)
            right[i] = right[i+1] * nums[i];
        
        vector<long long int> ans(n);
        ans[0] = right[1];
        ans[n-1] = left[n-2];
        
        for(int i=1; i<n-1; i++)
            ans[i] = left[i-1] * right[i+1];
            
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t; // number of test cases
    cin >> t;
    while (t--) {
        int n; // size of the array
        cin >> n;
        vector<long long int> arr(n), vec(n);

        for (int i = 0; i < n; i++) // input the array
        {
            cin >> arr[i];
        }
        Solution obj;
        vec = obj.productExceptSelf(arr); // function call

        for (int i = 0; i < n; i++) // print the output
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
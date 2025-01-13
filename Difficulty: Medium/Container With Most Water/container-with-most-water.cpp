//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int maxWater(vector<int> &arr) {
        int left = 0, right = arr.size() - 1;
        int res = 0;
        while(left < right) {
            
            // Find the water stored in the container between 
            // arr[left] and arr[right]
            int water = min(arr[left], arr[right]) * (right - left);
            res = max(res, water);
          
            if(arr[left] < arr[right])
                left += 1;
            else
                right -= 1;
        }
      
        return res;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxWater(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
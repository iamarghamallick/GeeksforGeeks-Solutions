//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:

    // Function to return length of longest subsequence of consecutive integers.
    int longestConsecutive(vector<int>& arr) {
        unordered_map<int, int> mp;
         
        int n = arr.size();
         
        for(int i=0; i<n; i++)
            mp[arr[i]]++;
        
        int mini = *min_element(begin(arr), end(arr));
        int maxi = *max_element(begin(arr), end(arr));
        int maxConsecutive = INT_MIN;
         
        int count = 0 ; 
         
        for(int i = mini; i <= maxi; i++) {
            if(mp.find(i) != mp.end())
                count++;
            else
                count = 0;
                 
            maxConsecutive = max(maxConsecutive, count);
        }
        
        return maxConsecutive;
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
        int res = ob.longestConsecutive(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
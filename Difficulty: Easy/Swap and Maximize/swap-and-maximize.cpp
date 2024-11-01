//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// long long int maxSum(int arr[], int n);

// } Driver Code Ends
class Solution {
  public:
    long long maxSum(vector<int>& arr) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end());
        vector<int> rearranged(2*n);
        int left = 0;
        int right = n-1;
        
        for(int i=0; i<n; i++) {
            if(i%2 == 0) 
                rearranged[i] = arr[right--];
            else
                rearranged[i] = arr[left++]; 
        }
        
        int maxSum = 0;
        for (int i = 0; i<n; i++) 
            maxSum += abs(rearranged[i] - rearranged[(i + 1) % n]); // Circular difference
        
        return maxSum;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore any newline character left in the buffer
    while (t--) {
        string line;
        getline(cin, line); // Read the entire line of input
        stringstream ss(line);
        vector<int> arr;
        int num;

        // Parse the input line into integers and add to the vector
        while (ss >> num) {
            arr.push_back(num);
        }

        Solution ob;
        long long ans = ob.maxSum(arr);

        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
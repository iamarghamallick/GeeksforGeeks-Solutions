//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int search(vector<int>& arr, int key) {
        int left = 0, right = arr.size() - 1;
        
        while(left <= right) {
            int mid = (left + right) / 2;
            
            if(arr[mid] == key)
                return mid;
                
            if(arr[left] <= arr[mid]) {
                // 1st half is sorted
                if(key >= arr[left] && key < arr[mid])
                    right = mid - 1;
                else 
                    left = mid + 1;
            } else {
                // 2nd half is sorted
                if(key > arr[mid] && key <= arr[right])
                    left = mid + 1;
                else 
                    right = mid - 1;
            }
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends
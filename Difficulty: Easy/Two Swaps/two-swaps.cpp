//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int findUnsortedCount(vector<int> &arr) {
        int count = 0;
        
        for(int i=0; i<arr.size(); i++)
            if(arr[i] != i+1)
                count++;
                
        return count;
    }
    
    void swapOne(vector<int> &arr) {
        int count = 0;
        
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] != i+1) {
                int temp = arr[i];
                arr[i] = arr[temp - 1];
                arr[temp - 1] = temp;
                break;
            }
        }
    }
    
    bool checkSorted(vector<int> &arr) {
        int count = findUnsortedCount(arr);
        
        if(count == 0 || count == 3)
            return true;
            
        if(count == 4) {
            swapOne(arr);
            swapOne(arr);
            return findUnsortedCount(arr) == 0;
        }
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        vector<int> arr;
        while (ss >> num)
            arr.push_back(num);

        Solution ob;
        bool ans = ob.checkSorted(arr);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

// } Driver Code Ends
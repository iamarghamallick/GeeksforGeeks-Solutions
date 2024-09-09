//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void swap(int *a, int *b) {
        int temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void sort012(vector<int>& arr) {
        int n = arr.size();
        int left = 0, mid = 0, right = n - 1;
        
        while(mid <= right) {
            if(arr[mid] == 0) {
                swap(&arr[left], &arr[mid]);
                left++;
                mid++;
            } else if(arr[mid] == 1) {
                mid++;
            } else {
                swap(&arr[mid], &arr[right]);
                right--;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        vector<int> a;
        string input;
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
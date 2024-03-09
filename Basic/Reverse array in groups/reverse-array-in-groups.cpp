//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
public:
    //Function to reverse every sub-array group of size k.
    void swap(long long *a, long long *b) {
        long long temp = *a;
        *a = *b;
        *b = temp;
    }
    
    void reverseInGroups(vector<long long>& arr, int n, int k){
        // code here
        int left = 0, right = k-1;
        
        while(right < n) {
            int l = left, r = right;
            while(l < r) {
                swap(&arr[l], &arr[r]);
                l++; r--;
            }
            
            left += k;
            right += k;
        }
        
        right = n-1;
        
        while(left < right) {
            swap(&arr[left], &arr[right]);
            left++; right--;
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t; 
    cin >> t; 
    while(t--){ 
        int n;
        cin >> n; 
        vector<long long> arr; 
        int k;
        cin >> k; 

        for(long long i = 0; i<n; i++)
        {
            long long x;
            cin >> x; 
            arr.push_back(x); 
        }
        Solution ob;
        ob.reverseInGroups(arr, n, k);
        
        for(long long i = 0; i<n; i++){
            cout << arr[i] << " "; 
        }
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends
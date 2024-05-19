//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution{
    public:
    int findClosest(int n, int k, int arr[]) {
        int dif = INT_MAX, ans = -1;
        
        for(int i=0; i<n; ++i) {
            if(abs(k-arr[i]) <= dif) {
                dif = abs(k-arr[i]);
                ans = arr[i];
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
    public:
    // naive approch -> O(n^2)
    // int countPairs(int arr[], int n ) {
    //     for(int i=0; i<n; i++)
    //         arr[i] = i * arr[i];
            
    //     int count = 0;
    //     for(int i=0; i<n; i++)
    //         for(int j=i+1; j<n; j++)
    //             if(arr[i] > arr[j])
    //                 count++;
        
    //     return count;
    // }
    
    int merge(int arr[], int temp[], int left, int mid, int right) {
        int count = 0;
        int i = left;
        int j = mid;
        int k = left;
        
        while(i <= mid - 1 && j <= right) {
            if(arr[i] <= arr[j])
                temp[k++] = arr[i++];
            else {
                temp[k++] = arr[j++];
                
                // this is the main part
                // this part is tricky
                // read here : 
                // https://www.geeksforgeeks.org/inversion-count-in-array-using-merge-sort/
                count += mid - i;
            }
        }
        
        while(i <= mid - 1)
            temp[k++] = arr[i++];
            
        while(j <= right)
            temp[k++] = arr[j++];
        
        for(i = left; i<=right; i++)
            arr[i] = temp[i];
        
        return count;
    }
    
    int mergeSort(int arr[], int temp[], int left, int right) {
        int count = 0;
        
        if(left < right) {
            int mid = (left + right) / 2;
            
            count += mergeSort(arr, temp, left, mid);
            count += mergeSort(arr, temp, mid + 1, right);
            
            count += merge(arr, temp, left, mid + 1, right);
        }
        
        return count;
    }
    
    // Merge Sort Approch -> O(n log(n))
    int countPairs(int arr[], int n) {
        for(int i=0; i<n; i++)
            arr[i] = i * arr[i];
        
        int temp[n];
        return mergeSort(arr, temp, 0, n - 1);
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	Solution ob;
    	cout<<ob.countPairs(a, n)<<endl;
    }
}
// } Driver Code Ends
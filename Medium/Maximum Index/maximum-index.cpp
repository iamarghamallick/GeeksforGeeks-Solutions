//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    int maxIndexDiff(int a[], int n) { 
        // Your code here
        int* leftMin = new int[n];
        int* rightMax = new int[n];

        // Preprocess to find the minimum element on the left of each element
        leftMin[0] = a[0];
        for (int i = 1; i < n; i++)
            leftMin[i] = min(leftMin[i - 1], a[i]);

        // Preprocess to find the maximum element on the right of each element
        rightMax[n - 1] = a[n - 1];
        for (int i = n - 2; i >= 0; i--)
            rightMax[i] = max(rightMax[i + 1], a[i]);

        int maxDiff = 0;
        int i = 0, j = 0;

        // Compare elements in leftMin and rightMax to find the maximum difference
        while (i < n && j < n) {
            if (leftMin[i] <= rightMax[j]) {
                maxDiff = max(maxDiff, j - i);
                j++;
            } else  i++;
        }

        delete[] leftMin;
        delete[] rightMax;

        return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int minimizeDifference(int n, int k, vector<int> &arr) {
        vector<int> leftMin(n, arr[0]), leftMax(n, arr[0]),
                    rightMin(n, arr[n-1]), rightMax(n, arr[n-1]);
        
        for(int i=1; i<n; i++) {
            leftMin[i] = min(leftMin[i-1], arr[i]);
            leftMax[i] = max(leftMax[i-1], arr[i]);
            
            rightMin[n-1-i] = min(rightMin[n-i], arr[n-1-i]);
            rightMax[n-1-i] = max(rightMax[n-i], arr[n-1-i]);
        }
        
        int ans = INT_MAX;
        
        for(int i=k-1; i<n; i++) {
            int currMin, currMax;
            
            if(i - k < 0) {
                // left most k elements
                currMin = rightMin[i + 1];
                currMax = rightMax[i + 1];
            } else if(i == n - 1) {
                // right most k elements
                currMin = leftMin[i - k];
                currMax = leftMax[i - k];
            } else {
                currMin = min(leftMin[i - k], rightMin[i + 1]);
                currMax = max(leftMax[i - k], rightMax[i + 1]);
            }
            
            ans = min(ans, abs(currMax - currMin));
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        int k;
        scanf("%d",&k);
        
        
        vector<int> arr(n);
        Array::input(arr,n);
        
        Solution obj;
        int res = obj.minimizeDifference(n, k, arr);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int splitArray(int arr[] ,int N, int K) {
        // code here
        long long low = *max_element(arr, arr + N);
        long long high = accumulate(arr, arr + N, 0LL);

        while (low < high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(arr, N, K, mid))     high = mid;
            else    low = mid + 1;
        }

        return low;
    }
    
    private:
    bool isPossible(int arr[], int N, int K, long long mid) {
        int count = 1;
        long long sum = 0;

        for (int i = 0; i < N; ++i) {
            sum += arr[i];
            if (sum > mid) {
                sum = arr[i];
                count++;
            }
        }

        return count <= K;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
// An efficient C++ program to compute 
// sum of bitwise OR of all pairs
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution{
    public:
    // Returns sum of bitwise OR
    // of all pairs
    long long int sumXOR(int arr[], int n)
    {
    	//Complete the function
    	long long totalXOR = 0;

        for (int i = 0; i < 32; ++i) {
            int countSetBits = 0; // Count of elements with i'th bit set
            for (int j = 0; j < n; ++j) {
                if (arr[j] & (1 << i)) {
                    countSetBits++;
                }
            }
            // For the i'th bit, count of set bits and unset bits
            // contributes countSetBits * (n - countSetBits) to the total XOR sum
            totalXOR += (1LL << i) * countSetBits * (n - countSetBits);
        }

        return totalXOR;
    }
};

//{ Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	 int n ;
	 cin>>n;
	 int arr[n+1];
	 for( int i=0;i<n;i++)
	    cin>>arr[i];
	 Solution ob;
	 cout<<ob.sumXOR(arr, n)<<endl;
	}	
	return 0;
}

// } Driver Code Ends
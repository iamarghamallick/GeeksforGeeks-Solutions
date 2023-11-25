//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	void shuffleArray(int arr[], int n) {
	    // Your code goes here
	    int x = 10000;
	    for(int i=0; i<n/2; i++) {
	        arr[i] = arr[i]+arr[n/2+i]*x;
	    }
	    
	    int j = n-1;
	    for(int i=n/2-1; i>=0; i--) {
	        arr[j] = arr[i]/x;
	        arr[j-1] = arr[i]%x;
	        j -= 2;
	    }
	}
		 

};

//{ Driver Code Starts.


int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
    	int n;
	    cin>>n;
	    int a[n] ;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }


       

        Solution ob;
        ob.shuffleArray(a, n);

		for (int i = 0; i < n; i++) 
			cout << a[i] << " ";
    
	
        
	    cout << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends
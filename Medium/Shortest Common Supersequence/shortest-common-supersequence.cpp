//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++


class Solution
{
    public:
    //Function to find length of shortest common supersequence of two strings.
    int shortestCommonSupersequence(string x, string y, int m, int n)
    {
        //code here
        int arr[m+1][n+1];
        
        for(int i=m; i>=0; i--) {
            for(int j=n; j>=0; j--) {
                if(i==m || j==n)    arr[i][j] = 0;
                else if(x[i]==y[j]) arr[i][j] = arr[i+1][j+1]+1;
                else    arr[i][j] = max(arr[i+1][j], arr[i][j+1]);
            }
        }
        
        int common = arr[0][0];
        return m+n-common;
    }
};

//{ Driver Code Starts.

int main()
{   
    
    int t;
    
    //taking total testcases
    cin >> t;
    while(t--){
    string X, Y;
    //taking String X and Y
	cin >> X >> Y;
	
	//calling function shortestCommonSupersequence()
	Solution obj;
	cout << obj.shortestCommonSupersequence(X, Y, X.size(), Y.size())<< endl;
    }
	return 0;
}


// } Driver Code Ends
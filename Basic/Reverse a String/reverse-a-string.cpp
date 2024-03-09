//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    string reverseWord(string str) {
        // Your code goes here
        int left = 0, right = str.size()-1;
        
        while(left < right) {
            char temp = str[left];
            str[left] = str[right];
            str[right] = temp;
            
            left++; right--;
        }
        
        return str;
    }
};



//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
    	string s;
    	cin >> s;
    	Solution ob;
    	cout << ob.reverseWord(s) << endl;
	}
	return 0;
	
}


// } Driver Code Ends
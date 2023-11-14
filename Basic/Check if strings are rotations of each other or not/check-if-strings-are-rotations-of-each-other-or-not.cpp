//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if two strings are rotations of each other or not.
    bool areRotations(string s1,string s2)
    {
        // Your code here
        int n = s1.size();
        vector<int> startingIndex;
        
        for(int j=0; j<n; j++) {
            if(s1[0] == s2[j]) 
                startingIndex.push_back(j);
        }
        
        if(startingIndex.size() == 0)     return 0;
        
        for(int k=0; k<startingIndex.size(); k++) {
            int j = startingIndex[k];
            for(int i=0; i<n; i++) {
                if(s1[i] != s2[j]) {
                    if(k == startingIndex.size()-1)     return 0;
                    break;
                }
                if(i == n-1)    return 1;
                j = (j+1)%n;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        Solution obj;
        cout<<obj.areRotations(s1,s2)<<endl;

    }
    return 0;
}

// } Driver Code Ends
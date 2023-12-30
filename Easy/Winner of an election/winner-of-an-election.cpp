//{ Driver Code Starts
#include <iostream>
#include <map>
#include <algorithm>
#include <cstdlib>
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
  public:
  
    //Function to return the name of candidate that received maximum votes.
    vector<string> winner(string arr[], int n) {
        // Your code here
        // Return the string containing the name and an integer
        // representing the number of votes the winning candidate got
        unordered_map<string, int> map;
        
        int MAX = 0;
        string VOTER = arr[0];
        for(int i=0; i<n; i++) {
            map[arr[i]]++;
            if(map[arr[i]] == MAX)
                VOTER = VOTER.compare(arr[i]) < 0 ? VOTER : arr[i];
            else if(map[arr[i]] > MAX) {
                MAX = max(MAX, map[arr[i]]);
                VOTER = arr[i];
            }
        }
            
        return { VOTER, to_string(MAX) };
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    
    for(int i=0;i<t;i++)
    {
        
        
        int n;
        cin>>n;
        
        string arr[n];
        
        for (int i=0;i<n;i++)
        cin>>arr[i];
        Solution obj;
        vector<string> result = obj.winner(arr,n);
        
        cout<<result[0] << " " << result[1] << endl;
    }
    return 0;
}

// } Driver Code Ends
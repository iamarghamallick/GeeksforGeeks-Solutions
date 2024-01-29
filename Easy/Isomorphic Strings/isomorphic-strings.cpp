//{ Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

// } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2) {
        // Your code here
        if(str1.size() != str2.size())  return false;
        
        unordered_map<char, char> map;
        
        for(int i=0; i<str1.size(); i++) {
            // if str1[i] is already present as a key in map
            if(map.count(str1[i])) {
                if(map[str1[i]] != str2[i])
                    return false;
            } else {
                // if str2[i] is present as a value in map
                vector<char> arr;
                for(auto it: map)
                    arr.push_back(it.second);
                
                if(find(arr.begin(), arr.end(), str2[i]) != arr.end())
                    return false;
                else
                    map[str1[i]] = str2[i];
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}
// } Driver Code Ends
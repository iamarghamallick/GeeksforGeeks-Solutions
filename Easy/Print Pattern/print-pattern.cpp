//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> pattern(int N){
        // code here
        vector<int> v;
        int temp = N;
        
        while(temp > 0) {
            v.push_back(temp);
            temp -= 5;
        }
        
        v.push_back(temp);
        temp += 5;
        
        while(temp < N + 1) {
            v.push_back(temp);
            temp += 5;
        }
        
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        vector<int> ans = ob.pattern(N);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends
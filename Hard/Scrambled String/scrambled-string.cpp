//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    public:
    
    // // Approch1 : Recursive Solution
    // bool solve(string a, string b) {
    //     // Base Cases
    //     if(a.compare(b) == 0)   return true;
    //     if(a.size() <= 1)   return false;
        
    //     int n = a.size();
    //     bool flag = false;
        
    //     // Next Logic
    //     for(int i=1; i<=n-1; i++) {
    //         // Condition1 ->
    //         // Check if S2[0...i] is a scrambled
    //         // string of S1[0...i] and if S2[i+1...n]
    //         // is a scrambled string of S1[i+1...n]
    //         bool condition1 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i));
            
    //         // Condition2 ->
    //         // Check if S2[0...i] is a scrambled
    //         // string of S1[n-i...n] and S2[i+1...n]
    //         // is a scramble string of S1[0...n-i-1]
    //         bool condition2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i));
            
    //         if(condition1 || condition2) {
    //             flag = true;
    //             break;
    //         }
    //     }
        
    //     return flag;
    // }
    
    // Approch2 : Recursive Solution with Memoization
    // Global map to store dynamic results
    unordered_map<string, bool> map;
    
    bool solve(string a, string b) {
        // Base Cases
        if(a.compare(b) == 0)   return true;
        if(a.size() <= 1)   return false;
        
        int n = a.size();
        bool flag = false;
        
        // make key of type string for search in map
        string key = (a + " " + b);
        // checking if both string are before calculated or not
        // if calculated means find in map then return it's
        // value
        if (map.find(key) != map.end()) 
            return map[key];
        
        // Next Logic
        for(int i=1; i<=n-1; i++) {
            // Condition1 ->
            // Check if S2[0...i] is a scrambled
            // string of S1[0...i] and if S2[i+1...n]
            // is a scrambled string of S1[i+1...n]
            bool condition1 = solve(a.substr(0, i), b.substr(n-i, i)) && solve(a.substr(i, n-i), b.substr(0, n-i));
            
            // Condition2 ->
            // Check if S2[0...i] is a scrambled
            // string of S1[n-i...n] and S2[i+1...n]
            // is a scramble string of S1[0...n-i-1]
            bool condition2 = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i, n-i), b.substr(i, n-i));
            
            if(condition1 || condition2) {
                flag = true;
                break;
            }
        }
        
        // add key & flag value to map (store for future use)
        // so next time no required to calculate it again
        return map[key] = flag;
    }
    
    bool isScramble(string S1, string S2){
        return solve(S1, S2);
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
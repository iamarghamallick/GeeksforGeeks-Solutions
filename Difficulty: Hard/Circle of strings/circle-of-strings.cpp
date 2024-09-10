//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int isCircle(vector<string> &arr) {
        int n = arr.size();
        unordered_map<char, vector<char>> adj;
        for(int i=0; i<n; i++) {
            int u = arr[i][0];
            int v = arr[i][arr[i].size() - 1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        int count = 0;
        unordered_map<char, bool> visited;
        for(int i=0; i<n; i++) {
            if(!visited[arr[i][0]]) {
                DFS(arr[i][0], adj, visited);
                count++;
            }
        }
        
        int odd = 0;
        for(auto i : adj)
            if(adj[i.first].size() & 1)
                odd++;
                
        if(count > 1 || odd != 0)
            return 0;
        
        return 1;
    }

  private:
    void DFS(char u, unordered_map<char, vector<char>> &adj, unordered_map<char, bool> &visited) {
        visited[u] = true;
        
        for(auto v : adj[u])
            if(!visited[v])
                DFS(v, adj, visited);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends
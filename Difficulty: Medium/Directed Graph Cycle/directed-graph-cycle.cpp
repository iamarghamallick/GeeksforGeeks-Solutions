//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool dfsCheck(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &pathVisited) {
        visited[node] = true;
        pathVisited[node] = true;
        
        for(auto it: adj[node]) {
            if(!visited[it]) {
                if(dfsCheck(it, adj, visited, pathVisited) == true) {
                    return true;
                }
            } else if(pathVisited[it]) {
                return true;
            }
        }
        
        pathVisited[node] = false;
        return false;
    }
    
    bool isCyclic(int V, vector<vector<int>> &edges) {
        vector<vector<int>> adj(V+1);
        for(auto &x : edges)
            adj[x[0]].push_back(x[1]);
        
        vector<bool> visited(V+1, false), pathVisited(V+1, false);
        
        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                if(dfsCheck(i, adj, visited, pathVisited) == true) {
                    return true;
                }
            }
        }
        
        return false;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V, E;
        cin >> V >> E;
        cin.ignore();
        vector<vector<int>> edges;
        for (int i = 1; i <= E; i++) {
            int u, v;
            cin >> u >> v;
            edges.push_back({u, v});
        }

        Solution obj;
        bool ans = obj.isCyclic(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";
    }
    return 0;
}
// } Driver Code Ends
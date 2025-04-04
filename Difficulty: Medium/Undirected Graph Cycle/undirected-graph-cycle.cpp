//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<int>adj[V];
        for(auto &it:edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<bool>vis(V, 0);
        vector<int>par(V, -1);
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty()){
                    int node=q.front();
                    q.pop();
                    
                    for(auto &ngbr:adj[node]){
                        if(!vis[ngbr]){
                            vis[ngbr]=1;
                            par[ngbr]=node;
                            q.push(ngbr);
                        }else if(par[node]!=ngbr) return 1;
                    }
                }
            }
        }
        return 0;
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
        bool ans = obj.isCycle(V, edges);
        if (ans)
            cout << "true\n";
        else
            cout << "false\n";

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends
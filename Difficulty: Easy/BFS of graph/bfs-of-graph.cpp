//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    void bfshelper(int src, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans) {
        queue<int> q;
        q.push(src);
        visited[src] = true;

        while (!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);

            for (auto i : adj[front]) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    vector<int> bfs(vector<vector<int>> &adj) {
        int v = adj.size();
        vector<int> ans;
        vector<bool> visited(v, false);
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                bfshelper(i, adj, visited, ans);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    cin >> tc;
    cin.ignore();
    while (tc--) {
        int V;
        cin >> V;
        cin.ignore();
        // Use vector of vectors instead of array of vectors.
        vector<vector<int>> adj(V);

        for (int i = 0; i < V; i++) {
            string input;
            getline(cin, input);
            int num;
            vector<int> node;
            stringstream ss(input);
            while (ss >> num) {
                node.push_back(num);
            }
            adj[i] = node;
        }

        Solution obj;
        vector<int> ans = obj.bfs(adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
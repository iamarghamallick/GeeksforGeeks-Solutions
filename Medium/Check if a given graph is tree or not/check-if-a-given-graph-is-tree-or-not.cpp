//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Matrix
{
public:
    template <class T>
    static void input(vector<vector<T>> &A,int n,int m)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                scanf("%d ",&A[i][j]);
            }
        }
    }
 
    template <class T>
    static void print(vector<vector<T>> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            for (int j = 0; j < A[i].size(); j++)
            {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends
class Solution {
  public:
    bool helper(int u, int par, vector<int> &vis, vector<int> g[]){ 
        vis[u]=1; 
        bool flag = 1; 
        for (auto &c: g[u]){ 
            if (c==par) continue; 
            if (vis[c]) return false; 
            flag = flag & helper(c,u,vis,g); 
        } 
        return flag; 
    } 
   
    int isTree(int n, int m, vector<vector<int>> &adj) { 
        
        vector<int> g[n]; 
        for (int i=0; i<adj.size(); i++){ 
            g[adj[i][0]].push_back(adj[i][1]); 
            g[adj[i][1]].push_back(adj[i][0]); 
        } 
        vector<int> vis(n,0); 
        bool ans = helper(0,-1,vis,g); 
        for (auto &v: vis){ 
            if (v==0){ 
                ans = 0; break; 
            } 
        } 
        return ans; 
    } 
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n; 
        scanf("%d",&n);
        
        
        int m; 
        scanf("%d",&m);
        
        
        vector<vector<int>> edges(m, vector<int>(2));
        Matrix::input(edges,m,2);
        
        Solution obj;
        int res = obj.isTree(n, m, edges);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends
class Solution {
  public:
    int dfs(int node,int dest,vector<vector<int>>&adj,vector<int>&dp){
        if(node==dest){
            // successfull path
            return 1;
        }
        if(dp[node]!=-1){
            // if 2 comes after i have already calculated all its path
            return dp[node];
        }
        int ans=0;
        for(auto it:adj[node]){
            // if i am 2 i will explore all path
            ans+=dfs(it,dest,adj,dp);
        }
        return dp[node]=ans;
    }
    int countPaths(vector<vector<int>>& edges, int V, int src, int dest) {
        // kind of like dp
        // where i will store how many path are possible from src to any node
        // i would just do dfs and check if i end up at dest
        vector<int>dp(V,-1);
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        
        return dfs(src,dest,adj,dp);
    }
};
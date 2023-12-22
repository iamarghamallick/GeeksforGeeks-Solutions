//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> ans; 
        vector<pair<int,pair<int,int>>> temp;
        
        for(int i=0; i<N; i++)
            temp.push_back({F[i],{i,S[i]}}); 

        sort(temp.begin(),temp.end()); 
        ans.push_back(temp[0].second.first+1); 
        int tocompare = temp[0].first; 
        
        for(int i=0; i<N-1; i++) { 
            if(tocompare < temp[i+1].second.second){ 
                int toadd = temp[i+1].second.first+1; 
                ans.push_back(toadd); 
                tocompare = temp[i+1].first; 
            }
        } 
        sort(ans.begin(),ans.end()); 
        
        return ans; 
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> S(n),F(n);
        for(int i=0;i<n;i++){
            cin>>S[i];
        }
        for(int i=0;i<n;i++){
            cin>>F[i];
        }
        Solution ob;
        vector<int> ans=ob.maxMeetings(n,S,F);
        for(int i=0;i<ans.size();i++){
            cout<<ans[i];
            if(i!=ans.size()-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends
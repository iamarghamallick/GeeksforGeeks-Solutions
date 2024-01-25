//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{   
public:
    void SieveOfEratosthenes(int n, vector<bool> &prime) { 
        for (int p = 2; p * p <= n; p++) { 
            if (prime[p] == true) { 
                for (int i = p * p; i <= n; i += p) 
                    prime[i] = false; 
            } 
        } 
    }
    
    int solve(int num1,int num2) {   
        //code here
        vector<bool> prime(10000, 1);
        SieveOfEratosthenes(9999, prime);
        int ans = 0;
        queue<int> q;
        q.push(num1);
        while (!q.empty()) {
            int sz = q.size();
            for (int i=0; i<sz; i++) {
                int val = q.front();
                q.pop();
                if (val == num2) return ans;
            
                string s = to_string(val);
                for (int j = 0; j < 4; j++) {
                    char c = s[j];
                    for (int k = 0; k < 10; k++) {
                        if (k == 0 && j == 0) continue; 
                        s[j] = '0' + k; 
                        int temp = stoi(s); 
                        if (prime[temp]) { 
                            q.push(temp); 
                            prime[temp] = 0; 
                        } 
                    } 
                    s[j] = c; 
                } 
            } 
            ans++; 
        }
    }
};


//{ Driver Code Starts.
signed main()
{
  int t;
  cin>>t;
  while(t--)
  {
      int num1,num2;
      cin>>num1>>num2;
      Solution obj;
      int answer=obj.solve(num1,num2);
      cout<<answer<<endl;
  }
}
// } Driver Code Ends
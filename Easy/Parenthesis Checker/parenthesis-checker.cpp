//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    char opening(char c) {
        if(c==')')  return '(';
        if(c=='}')  return '{';
        if(c==']')  return '[';
        
        return c;
    }
    
    bool isOpening(char c) {
        if(c=='(' || c=='{' || c=='[')
            return true;
            
        return false;
    }
    
    bool ispar(string x)
    {
        // Your code here
        stack<char> st;
        
        for(int i=0; i<x.size(); i++) {
            if(isOpening(x[i]))
                st.push(x[i]);
            else {
                if(!st.empty() && opening(x[i]) == st.top()) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        
        if(!st.empty())     return false;
        
        return true;
    }

};

//{ Driver Code Starts.

int main()
{
   int t;
   string a;
   cin>>t;
   while(t--)
   {
       cin>>a;
       Solution obj;
       if(obj.ispar(a))
        cout<<"balanced"<<endl;
       else
        cout<<"not balanced"<<endl;
   }
}
// } Driver Code Ends
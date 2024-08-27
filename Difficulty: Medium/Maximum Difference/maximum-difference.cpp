//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method */
    int findMaxDiff(vector<int> &arr) {
        int n = arr.size();
        vector<int> lsa(n, 0), rsa(n, 0);
        
        stack<int> st;
        st.push(0);
        st.push(arr[0]);
        
        for(int i=1; i<n; i++) {
            while(st.top() >= arr[i])
                st.pop();
            lsa[i] = st.top();
            st.push(arr[i]);
        }
        
        st.push(0);
        st.push(arr[n-1]);
        
        for(int i=n-2; i>=0; i--) {
            while(st.top() >= arr[i])
                st.pop();
            rsa[i] = st.top();
            st.push(arr[i]);
        }
        
        int ans = INT_MIN;
        for(int i=0; i<n; i++)
            ans = max(ans, abs(rsa[i] - lsa[i]));
            
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.findMaxDiff(arr) << endl;
    }
    return 0;
}

// } Driver Code Ends
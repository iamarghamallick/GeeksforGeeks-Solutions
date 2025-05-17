//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    vector<int> merge(vector<int>&v1 , vector<int>&v2) {
        int n = v1.size() , m = v2.size();
          
        vector<int>ans(n+m);
      
        int index = 0;
        int index1= 0,index2 = 0;
      
        while(index1 < n && index2 < m){
            if(v1[index1] <= v2[index2])
                ans[index++] = v1[index1++];
            else
              ans[index++] = v2[index2++];
        }
        
        while(index1 < n) ans[index++] = v1[index1++];
        while(index2 < m) ans[index++] = v2[index2++];
        
        return ans;
    }
  
  public:
    vector<int> sortArray(vector<int> &arr, int A, int B, int C) {
        //Linear function
        if(A == 0) {
            for(int &i : arr) i = B*i + C;
            
            if(B >= 0)
                //increasing function y = b*x + c;
                return arr;
            
            // b < 0 --> decreasing function y = b*x + 
            reverse(arr.begin() , arr.end());
            
            return arr;
        }
        
        // find minimum or maximum value y = ax^2 + bx + c
        // dy/dx = 2ax + b
        // put dy/dx = 0
        // 2ax + b = 0 --> x = -b/2a
        
        double x = (double)(-B) / (2*A);
        vector<int> a1,a2;
            
        for(int i : arr){
            int d = A*i*i + B*i + C;
            if((double)i <= x)
                a1.push_back(d);
            else
                a2.push_back(d);
        }
        
        if(A > 0)
            //up side paragola
            reverse(a1.begin() , a1.end());
        else
            //down side paragola
            reverse(a2.begin() , a2.end());
        
        return merge(a1,a2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        getline(cin, input);

        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        int a, b, c;
        cin >> a >> b >> c;
        cin.ignore();

        Solution obj;
        vector<int> ans = obj.sortArray(arr, a, b, c);
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
        cout << endl;

        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
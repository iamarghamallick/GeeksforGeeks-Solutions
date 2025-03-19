//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int maxProfit(vector<int>& prices, int k) {
        int n = prices.size();
        vector<vector<int>> curr(k+2, vector<int>(2, 0));
        vector<vector<int>> next(k+2, vector<int>(2, 0));

        for(int i = n-1; i >= 0; i--){
            for(int limit = k; limit >= 0; limit--){
                for(int buy = 0; buy <= 1; buy++){
                    int ans = 0;
                    int include = 0;
                    int exclude = 0;
                    if(limit < k){
                        if(buy){
                            include = -1*prices[i] + next[limit][false];
                            exclude =  next[limit][true];  
                        }
                        else{
                            include = prices[i] + next[limit+1][true];   
                            exclude = next[limit][false];   
                        }
                    }
                
                    ans = max(include, exclude);
                    curr[limit][buy] = ans;
                }
            }
            next = curr;
        }

        return next[0][1];
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
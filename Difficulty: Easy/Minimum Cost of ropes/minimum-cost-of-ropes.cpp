//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return the minimum cost of connecting the ropes.
    long long minCost(vector<long long>& arr) {
        if(arr.size() <= 1)
            return 0;
            
        priority_queue<long long, vector<long long>, greater<long long>> pq(arr.begin(), arr.end());
        long long cost = 0;
        while(!pq.empty()) {
            int num1 = pq.top(); pq.pop();
            int num2 = pq.top(); pq.pop();
            cost += (num1 + num2);
            if(!pq.empty())
                pq.push(num1 + num2);
        }
        return cost;
    }
};


//{ Driver Code Starts.

int main() {
    long long t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        long long num;
        vector<long long> a;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        cout << ob.minCost(a) << endl;
    }
    return 0;
}

// } Driver Code Ends
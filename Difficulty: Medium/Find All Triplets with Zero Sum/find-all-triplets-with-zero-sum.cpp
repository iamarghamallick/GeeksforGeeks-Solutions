//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<vector<int>> findTriplets(vector<int> &arr) {
        map<int,vector<pair<int,int>>> mp;
        set<vector<int>> res;
        for(int i=0; i<arr.size()-1; i++){
            for(int j=i+1; j<arr.size(); j++){
                int two_sum=arr[i]+arr[j];
                mp[two_sum].push_back({i,j});
            }
        }
        for(int i=0; i<arr.size(); i++){
            int tar=-arr[i];
            if(mp.find(tar)!=mp.end()){
                for (auto const& p : mp[tar]) {
                    if(p.first!=i && p.second!=i){
                        vector<int> vec = {i,p.first,p.second};
                        sort(vec.begin(), vec.end());
                        res.insert(vec);
                    }
                }
            }
        }
        vector<vector<int>> answer(res.begin(), res.end());
        return answer;
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
        Solution ob;

        vector<vector<int>> res = ob.findTriplets(arr);
        sort(res.begin(), res.end());
        if (res.size() == 0) {
            cout << "[]\n";
        }
        for (int i = 0; i < res.size(); i++) {
            for (int j = 0; j < res[i].size(); j++) {
                cout << res[i][j] << " ";
            }
            cout << endl;
        }
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int activitySelection(vector<int> &start, vector<int> &finish) {
        vector<vector<int>>vec;
        for(int i=0;i<start.size();i++){
            vec.push_back({finish[i], start[i]});
        }
        sort(vec.begin(), vec.end());
        
        int end=vec[0][0];
        int maxi=1;
        for(int i=1;i<vec.size();i++){
            if(vec[i][1]>end){
                maxi++;
                end=vec[i][0];
            }
        }
        return maxi;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        stringstream ss(input);
        vector<int> start;
        int num;
        while (ss >> num)
            start.push_back(num);
        getline(cin, input);
        ss.clear();
        vector<int> finish;
        ss.str(input);
        while (ss >> num)
            finish.push_back(num);

        Solution obj;
        cout << obj.activitySelection(start, finish) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends
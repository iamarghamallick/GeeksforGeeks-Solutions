//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        vector<double> ans;
        multimap<int, int> x;
        int n = arr.size();
        x.insert({arr[0], 1});
        auto it = x.begin();
        ans.push_back(arr[0]);
        for(int i=1; i<n; i++) {
            x.insert({arr[i], 1});
            if(i%2 != 0) {
                if(it->first > arr[i]) it--;
                double digit = it->first;
                it++;
                digit+=it->first;
                it--;
                ans.push_back(digit/2);
            } else {
                if(it->first <= arr[i])  it++;
                ans.push_back(it->first);
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends
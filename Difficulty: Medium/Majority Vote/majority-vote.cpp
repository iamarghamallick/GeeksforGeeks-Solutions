//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find the majority elements in the array
    vector<int> findMajority(vector<int>& nums) {
        int n = nums.size(), vote1 = 0, vote2 = 0, candidate1 = -1, candidate2 = -1;
        for(int i=0; i<n; i++) {
            if(nums[i] == candidate1)   vote1++;
            else if(nums[i] == candidate2)  vote2++;
            else if(vote1 == 0) {
                candidate1 = nums[i];
                vote1 = 1;
            }
            else if(vote2 == 0) {
                candidate2 = nums[i];
                vote2 = 1;
            }
            else {
                vote1--;
                vote2--;
            }
        }
        
        vote1 = 0, vote2 = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == candidate1)
                vote1++;
            else if(nums[i] == candidate2)
                vote2++;
        }
        
        vector<int> ans;
        if(vote1 > n/3) ans.push_back(candidate1);
        if(vote2 > n/3) ans.push_back(candidate2);
        
        return ans.size() == 0 ? vector<int>{-1} : ans;
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
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends
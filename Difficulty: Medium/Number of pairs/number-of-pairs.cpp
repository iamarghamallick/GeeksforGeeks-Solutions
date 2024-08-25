//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int count0 = 0, count1 = 0, count2 = 0, count3 = 0, count4 = 0;
    
    long long solve(int num, vector<int> &brr) {
        if(num == 0)
            return 0;
        if(num == 1)
            return count0;
        
        auto index = upper_bound(brr.begin(), brr.end(), num);
        long long ans = brr.end() - index;
        ans += count0 + count1;
        
        if(num == 2)
            ans -= count3 + count4;
        if(num == 3)
            ans += count2;
        
        return ans;
    }
    
    long long countPairs(vector<int> &arr, vector<int> &brr) {
        for(int num : brr) {
            if(num == 0)    count0++;
            else if(num == 1)   count1++;
            else if(num == 2)   count2++;
            else if(num == 3)   count3++;
            else if(num == 4)   count4++;
        }
        
        sort(brr.begin(), brr.end());
        
        long long count = 0;
        for(int num : arr)
            count += solve(num, brr);
            
        return count;
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends
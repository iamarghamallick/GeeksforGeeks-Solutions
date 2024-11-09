//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    string minSum(vector<int> &arr) {
        sort(arr.begin(), arr.end());
        string num1 = "", num2 = "";
        for(int i=0; i<arr.size(); i++) {
            if(i&1)
                num1 += arr[i] + '0';
            else
                num2 += arr[i] + '0';
        }
        int i1 = num1.size()-1, i2 = num2.size() - 1, carry = 0;
        string ans = "";
        while(i1 >= 0 || i2 >= 0) {
            int num11 = i1 >= 0 ? num1[i1] - '0' : 0;
            int num21 = i2 >= 0 ? num2[i2]-'0' : 0;
            ans += (num11 + num21 + carry) % 10 + '0';
            carry = (num11 + num21 + carry) / 10;
            i1--;
            i2--;
        }
        if(carry > 0)   ans += carry + '0';
        reverse(ans.begin(), ans.end());
        int zeroIndex = 0;
        while(zeroIndex < ans.length()) {
            if(ans[zeroIndex] == '0')
                zeroIndex++;
            else
                break;
        }
        return ans.substr(zeroIndex);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;
        string ans = ob.minSum(a);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <iostream>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string roundToNearest(string str) {
        int n = str.size();
        if(str[n-1] == '0')
            return str;
        if('1' <= str[n-1] && str[n-1] <= '5') {
            str[n-1] = '0';
            return str;
        }
        str[n-1] = '0';
        bool flag = true;
        for(int i=n-2; i>=0; i--) {
            if(str[i] == '9')
                str[i] = '0';
            else {
                str[i] = (char)(48 + (str[i] - '0' + 1));
                flag = false;
                break;
            }
        }
        if(flag)
            str = '1' + str;
        return str;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.roundToNearest(str) << endl;
    }

    return 0;
}
// } Driver Code Ends
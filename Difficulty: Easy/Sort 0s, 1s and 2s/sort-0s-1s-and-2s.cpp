//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void sort012(vector<int>& arr) {
        int zero = 0, one = 0, two = 0;
        for(int i=0; i<arr.size(); i++) {
            if(arr[i] == 0) zero++;
            else if(arr[i] == 1) one++;
            else    two++;
        }
        int i=0;
        while(zero--) arr[i++] = 0;
        while(one--) arr[i++] = 1;
        while(two--) arr[i++] = 2;
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
        int num;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            a.push_back(num);
        }
        Solution ob;
        ob.sort012(a);

        int n = a.size();
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }

        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
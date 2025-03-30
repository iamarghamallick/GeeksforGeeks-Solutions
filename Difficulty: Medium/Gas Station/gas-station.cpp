//{ Driver Code Starts
// C++ program to find union of
// two sorted arrays
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


/*You are required to complete this method*/
class Solution {
  public:
    int startStation(vector<int> &gas, vector<int> &cost) {
        int n = gas.size();
        
        // to find the biggest gap between cost and gas
        int temp = 0, index = 0;
        for(int i = 0; i < n; i++)
        {
            int sub = gas[i] - cost[i];
            if(sub > 0 && sub > temp)
            {
                index = i;
                temp = sub;
            }
        }
        
        // start from the most possible(biggest gap) index
        for(int i = index; i < index + n; i++)
        {
            int cur_gas = 0;
            for(int j = i; j < i + n; j++)
            {
                cur_gas += gas[j % n];
                cur_gas -= cost[j % n];
                if(cur_gas < 0)
                    break;
            }
            if(cur_gas >= 0) return i % n;
        }
        return -1;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function */
int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);

    while (t--) {

        vector<int> gas, cost;
        string input1;
        getline(cin, input1);
        stringstream ss(input1);
        int number1;
        while (ss >> number1) {
            gas.push_back(number1);
        }
        string input2;
        getline(cin, input2);
        stringstream sss(input2);
        int number2;
        while (sss >> number2) {
            cost.push_back(number2);
        }
        Solution ob;
        int ans = ob.startStation(gas, cost);

        cout << ans << endl;
        cout << "~\n";
    }

    return 0;
}

// } Driver Code Ends
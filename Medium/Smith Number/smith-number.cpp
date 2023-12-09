//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
    int sumOfDigits(int n) {
        int sum = 0;
        
        while(n) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        
        return sum;
    }
    
    int primeFactorSum(int n) {
        int count = 0;
        int sum = 0;
        
        int i = 2;
        
        while(n > 1) {
            if(n % i == 0) count++;
            if(n % i == 0) {
                if(i > 10) sum += sumOfDigits(i);
                else sum += i;
                n /= i;
            } else i++;
        }
        
        return count > 1 ? sum : 0;
    }
    
    int smithNum(int n) {
        // code here
        return sumOfDigits(n) == primeFactorSum(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends
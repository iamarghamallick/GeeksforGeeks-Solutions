//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // You need to complete this function

    // avoid space at the starting of the string in "move disk....."
    long long moves = 0;
    long long toh(int N, int start, int stop, int temp) {
        // Your code here
        if(N > 0) {
            toh(N-1, start, temp, stop);
            printf("move disk %d from rod %d to rod %d\n", N, start, stop);
            moves++;
            toh(N-1, temp, stop, start);
        }
        
        return moves;
    }

};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code Ends
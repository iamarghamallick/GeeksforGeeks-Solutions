//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

//User function Template for C++

class Solution {
    public:
    
    class TrieNode {
        public:
        TrieNode *zero, *one;
        int count;
        
        TrieNode() {
            zero = nullptr;
            one = nullptr;
        }
    };
    
    void insert(TrieNode *root, int n) {
        TrieNode *curr = root;
        
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(bit == 0) {
                if(curr->zero == nullptr) {
                    curr->zero = new TrieNode();
                }
                curr = curr->zero;
            } else {
                if(curr->one == nullptr) {
                    curr->one = new TrieNode();
                }
                curr = curr->one;
            }
        }
    }
    
    int findMaxXor(TrieNode *root, int n) {
        TrieNode *curr = root;
        
        int ans = 0;
        
        for(int i=31; i>=0; i--) {
            int bit = (n >> i) & 1;
            if(bit == 1) {
                if(curr->zero) {
                    ans += (1 << i);
                    curr = curr->zero;
                } else {
                    curr = curr->one;
                }
            } else {
                if(curr->one) {
                    ans += (1 << i);
                    curr = curr->one;
                } else {
                    curr = curr->zero;
                }
            }
        }
        
        return ans;
    }
    
    int maxXor(vector <int> arr) {
        int n = arr.size();
        
        TrieNode *root = new TrieNode();
        
        for(int i=0; i<n; i++)
            insert(root, arr[i]);
            
        int maxXor = 0;
        for(int i=0; i<n; i++)
            maxXor = max(maxXor, findMaxXor(root, arr[i]));
            
        return maxXor;
    }
    
};




//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
            cin >> arr[i];

        Solution ob;
        cout << ob.maxXor(arr) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends
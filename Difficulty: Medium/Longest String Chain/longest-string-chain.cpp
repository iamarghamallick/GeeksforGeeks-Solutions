//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    static bool comp(const string &s1, const string &s2)
    {
        return s1.size() < s2.size();
    }
    
    bool compare(string &s1, string &s2)
    {
        if(s1.size() != s2.size() + 1)
            return false;
            
        int first = 0, second = 0;
        
        while(first < s1.size())
        {
            if(s1[first] == s2[second])
            {
                first ++;
                second ++;
            }
            
            else
            {
                first ++;
            }
        }
        
        if(first == s1.size() && second == s2.size())
            return true;
            
        return false;
    }
    
    int longestStringChain(vector<string>& words) {
        // Code here
        
        sort(words.begin(), words.end(), comp);
        
        int n = words.size();
        vector<int> maxi(n, 1);
        int ans = 1;
        
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(compare(words[i], words[j]))
                {
                    maxi[i] = max(maxi[i], maxi[j] + 1);
                }
            }
            
            ans = max(ans, maxi[i]);
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
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
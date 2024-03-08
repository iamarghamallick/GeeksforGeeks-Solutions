//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	bool sameFreq(string s) {
	    // code here
	    unordered_map<char, int> freq;
        for(auto c : s)
            freq[c]++;
 
        unordered_map<int, int> freqCount;
        int minFreq = INT_MAX, maxFreq = INT_MIN;
 
        for(auto& p : freq) {
            minFreq = min(minFreq, p.second);
            maxFreq = max(maxFreq, p.second);
            freqCount[p.second]++;
        }
 
        if (freqCount.size() == 1)  return true; 
 
        if (freqCount.size() == 2 && ((freqCount[minFreq] == 1 && minFreq == 1) || (freqCount[maxFreq] == 1 && maxFreq - minFreq == 1)))
            return true;
 
        return false;
	}
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.sameFreq(s)<<endl;
    }
}



// } Driver Code Ends
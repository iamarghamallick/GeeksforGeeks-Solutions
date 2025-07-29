class Solution {
  public:
    vector<int> asciirange(string& s) {
        vector<int>lastOcc(26,-1);
        vector<int>firstOcc(26,-1);
        int n = s.size();
        
        // store last Occurence from end to start for each character
        for(int i = n-1 ; i>= 0 ; i--) {
            if(lastOcc[s[i]-'a'] == -1)
            lastOcc[s[i]-'a'] = i;
        }
        
        // store first Occurence from start to end for each character
        for(int i = 0 ; i < n ; i++) {
            if(firstOcc[s[i]-'a'] == -1)
            firstOcc[s[i]-'a'] = i;
        }
        
        // calculate the prefix sum from left to right that reduce the explicitly sum the
        // character between last and first occurence
        vector<int>left(n,0);
        int sum = 0;
        
        for(int i = 0 ; i < n ; i++) {
            int idx = s[i]-'a';
            sum += 97 + idx;
            left[i] = sum;
        }
        
        vector<int>ans;
        
        for(int i = 0 ; i < 26 ; i++) {
            if(firstOcc[i] == lastOcc[i] || firstOcc[i] +1 == lastOcc[i] || firstOcc[i] == -1 || lastOcc[i] == -1)
            continue;
            
            int fIdx = firstOcc[i];
            int lIdx = lastOcc[i];
            
            // to get the ascii sum between the first and occurence
            int sum = left[lIdx-1] - left[fIdx];
            ans.push_back(sum);
          
        }
        
        return ans;
    }
};
class Solution {
  public:
    int countDistinct(vector<int> &freq) {
        int count = 0;
        
        for(int fre : freq)
            if(fre > 0)
                count++;
                
        return count;
    }
    
    int substrCount(string &s, int k) {
        int ans = 0;
        vector<int> freq(26, 0);
        
        for(int i=0; i<=s.size()-k; i++) {
            if(i == 0) {
                for(int j=0; j<k; j++) {
                    freq[s[j] - 'a']++;
                }
            } else {
                freq[s[i-1] - 'a']--;
                freq[s[i-1+k] - 'a']++;
            }
            
            if(countDistinct(freq) == k-1)
                ans++;
        }
        
        return ans;
    }
};
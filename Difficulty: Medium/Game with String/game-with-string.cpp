class Solution {
  public:
    int minValue(string &s, int k) {
        vector<int> freq(26, 0);
        for(char c : s) freq[c - 'a']++;
        
        while(k) {
            int maxFreq = 0, maxFreqIdx = 0;
            for(int i=0; i<26; i++) {
                if(freq[i] > maxFreq) {
                    maxFreq = freq[i];
                    maxFreqIdx = i;
                }
            }
            
            freq[maxFreqIdx]--;
            k--;
        }
        
        int ans = 0;
        for(int num : freq) {
            ans += pow(num, 2);
        }
        
        return ans;
    }
};
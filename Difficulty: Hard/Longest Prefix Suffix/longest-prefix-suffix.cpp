class Solution {
  public:
    int getLPSLength(string &s) {
        int n = s.length();
        vector<int> lps(n);
        
        // len stores the length of longest prefix which
        // is also a suffix for the previous index
        int len = 0;
    
        // lps[0] is always 0
        lps[0] = 0;
    
        int i = 1;
        while (i < s.length()) {
            // If characters match, increment the size of lps
            if (s[i] == s[len]) {
                len++;
                lps[i] = len;
                i++;
            }
    
            // If there is a mismatch
            else {
                if (len != 0) {
                    // Update len to the previous lps value
                    // to avoid reduntant comparisons
                    len = lps[len - 1];
                }
                else {
                    // If no matching prefix found, set lps[i] to 0
                    lps[i] = 0;
                    i++;
                }
            }
        }
        
        // Last element of lps array will store the length of
        // longest prefix that is also suffix of entire string
        return lps[n - 1];
    }
};
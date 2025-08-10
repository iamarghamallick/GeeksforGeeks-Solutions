class Solution {
  public:
    int countPS(string &s) {
        int n = s.length();
        int res = 0;
    
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        
        // One length string is always palindrome 
        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }
    
        // Two length string is plaindrome if
        // both characters are same
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = true;
                res++;
            }
        }
    
        // Handle palindromes of length 
        // greater than 2 (gap >= 2)
        for (int gap = 2; gap < n; gap++) {
            for (int i = 0; i < n - gap; i++) {
                int j = i + gap;
    
                // Check if the current string is a palindrome
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = true;
                    res++;
                }
            }
        }
      
        return res;
    }
};
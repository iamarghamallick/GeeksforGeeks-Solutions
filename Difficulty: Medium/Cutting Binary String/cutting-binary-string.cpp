class Solution {
  public:
    unordered_set<int> powers;
    vector<int> dp;
    
    int solve(int i, string s) {
        int n = s.size();
        if(i >= n)  return 0; // base case
        if(dp[i] != -1) return dp[i];
        int ans = n+1, deci = 0;
        
        for(int j=i; j<n; j++) {
            deci = deci * 2 + (s[j] - '0');
            if(s[i] != '0' && powers.count(deci))
                ans = min(ans, 1 + solve(j+1, s));
        }
        
        return dp[i] = ans;
    }
  
    int cuts(string s) {
        int n = s.size();
        if(s[0] == '0') return -1;
        for(int p=1; p<=1e9; p*=5) powers.insert(p);
        dp = vector<int> (n+1, -1);
        int ans = solve(0, s);
        return ans > n ? -1 : ans;
    }
};
class Solution {
  public:
    string maxSubseq(string& s, int k) {
        int n = s.size();
        int toRemove = k;
        string ans = "";
        
        for(int i=0; i<s.size(); i++) {
            while(k && !ans.empty() && ans.back() < s[i]) {
                ans.pop_back();
                k--;
            }
            ans += s[i];
        }
    

        ans.resize(n - toRemove);
        return ans;
    }
};

class Solution {
  public:
    bool isPalindrom(string &s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
  
    void check(int idx, string &s, vector<string> &temp, vector<vector<string>> &ans) {
        if(idx >= s.size()) {
            ans.push_back(temp);
            return;
        }
        
        for(int i=idx+1; i<=s.size(); i++) {
            string curr = s.substr(idx, i - idx);
            if(isPalindrom(curr)) {
                temp.push_back(curr);
                check(i, s, temp, ans);
                temp.pop_back();
            }
        }
    }
  
    vector<vector<string>> palinParts(string &s) {
        vector<vector<string>> ans;
        vector<string> temp;
        check(0, s, temp, ans);
        return ans;
    }
};
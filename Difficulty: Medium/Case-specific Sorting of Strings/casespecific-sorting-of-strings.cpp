class Solution {
  public:
    bool isLower(char c) {
        return 0 <= c - 'a' && c - 'a' < 26;
    }
    
    string caseSort(string& s) {
        int n = s.size();
        string upper = "", lower = "";
        for(char c : s) {
            if(isLower(c))
                lower += c;
            else
                upper += c;
        }
        
        sort(upper.begin(), upper.end());
        sort(lower.begin(), lower.end());
        
        int uIdx = 0, lIdx = 0;
        for(int i=0; i<n; i++) {
            if(isLower(s[i])) {
                s[i] = lower[lIdx++];
            } else {
                s[i] = upper[uIdx++];
            }
        }
        
        return s;
    }
};
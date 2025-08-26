class Solution {
  public:
    bool isSubSeq(string& s1, string& s2) {
        int i=0, j=0;
        while(i<s1.size() && j<s2.size()) {
            if(s1[i] == s2[j]) {
                i++;
                j++;
            } else {
                j++;
            }
        }
        return i == s1.size();
    }
};
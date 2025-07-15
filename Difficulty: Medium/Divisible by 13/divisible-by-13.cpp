class Solution {
  public:
    bool divby13(string &s) {
        int n = 0;
        for(int i=0; i<s.size(); i++) {
            n = (n * 10 + (s[i] - '0')) % 13;
        }
        return n % 13 == 0;
    }
};
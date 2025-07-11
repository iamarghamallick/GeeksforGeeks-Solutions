class Solution {
  public:
    int countConsec(int n) {
        if(n == 2) return 1;
        
        int prev = 0;
        int curr = 1;
        int next, ans = 1;
        
        for(int i=3; i<=n; i++) {
            next = prev + curr;
            ans = ans*2 + next;
            prev = curr;
            curr = next;
        }
        
        return ans;
    }
};
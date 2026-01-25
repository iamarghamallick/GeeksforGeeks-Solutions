class Solution {
    int helper(int open, int close){
        if(open < 0 || close < 0)
            return 0;
        if(open == 0 && close == 1)
            return 1;
        int takeOpen = helper(open-1, close);
        int takeClose = 0;
        if(open < close)
            takeClose = helper(open, close-1);
        return takeOpen + takeClose;
    }
    
    int findWays(int n) {
        if(n%2 == 1)
            return 0;
        return helper(n/2, n/2);
    }
}

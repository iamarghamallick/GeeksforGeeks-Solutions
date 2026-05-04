class Solution {
    public boolean isBinaryPalindrome(int n) {
        String s = "";
        while(n > 0) {
            if((n&1) == 1) {
                s += "1";
            } else {
                s += "0";
            }
            n >>= 1;
        }
        
        return isPalindrome(s);
    }
    
    private boolean isPalindrome(String s) {
        int left = 0;
        int right = s.length() - 1;
        
        while(left <= right) {
            if(s.charAt(left) != s.charAt(right)) {
                return false;
            }
            left++;
            right--;
        }
        
        return true;
    }
};
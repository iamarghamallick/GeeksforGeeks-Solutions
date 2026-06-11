class Solution {
    public int findIndex(String s) {
        int n = s.length();
        int totalOpening = 0;
        for(char c: s.toCharArray()) {
            if(c == '(') {
                totalOpening++;
            }
        }
        
        int leftOpening = 0;
        int leftClosing = 0;
        int rightClosing;
        for(int i=0; i<n; i++) {
            rightClosing = n - totalOpening - leftClosing;
            if(leftOpening == rightClosing) {
                return i;
            }
            if(s.charAt(i) == ')') {
                leftClosing++;
            } else {
                leftOpening++;
            }
        }
        
        rightClosing = n - totalOpening - leftClosing;
        return leftOpening == rightClosing ? n : -1;
    }
}
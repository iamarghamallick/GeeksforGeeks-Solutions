class Solution {
    public boolean stringStack(String pat, String tar) {
        char[] patarr = pat.toCharArray();
        char[] tararr = tar.toCharArray();
        int i = patarr.length - 1;
        int j = tararr.length - 1;
        while(i >= 0 && j >= 0) {
            if(patarr[i] == tararr[j]) {
                i--;
                j--;
            } else {
                i -= 2;
            }
            if(j == -1) return true;
        }
        return false;
    }
}

class Solution {
    public int maxCharGap(String s) {
        int[] map = new int[26];
        int ans = -1;
        for(int i=0; i<26; i++) {
            map[i] = -1;
        }
        for(int i=0; i<s.length(); i++) {
            if(map[s.charAt(i) - 'a'] == -1) {
                map[s.charAt(i) - 'a'] = i;
            } else {
                ans = Math.max(ans, i - map[s.charAt(i) - 'a'] - 1);
            }
        }
        return ans;
    }
};
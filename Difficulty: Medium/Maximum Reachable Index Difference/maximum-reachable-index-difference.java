class Solution {
    public int maxIndexDifference(String s) {
        int jump = -1;
        int n = s.length();

        if (s.indexOf('a') == -1) {
            return -1;
        }

        int[] alph = new int[26];
        Arrays.fill(alph, -1);

        int ch = 0;

        for (int i = 0; i < n; i++) {
            if (ch == (s.charAt(i) - 'a')) {
                alph[s.charAt(i) - 'a'] = i;
                ch++;
            } else if (alph[s.charAt(i) - 'a'] != -1 && s.charAt(i) != 'a') {
                alph[s.charAt(i) - 'a'] = i;
            }
        }

        for (int j = 1; j < 26; j++) {
            if (alph[j] != -1) {
                jump = Math.max(jump, alph[j] - alph[0]);
            }
        }

        if (jump == -1 && alph[0] != -1) {
            return 0;
        }

        return jump;
    }
}
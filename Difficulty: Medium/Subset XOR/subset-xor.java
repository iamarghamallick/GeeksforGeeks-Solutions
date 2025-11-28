class Solution {
    public static ArrayList<Integer> subsetXOR(int n) {
        ArrayList<Integer> ans = new ArrayList<>();
        int totalXOR = 0;
        for (int i = 1; i <= n; i++) totalXOR ^= i;
        if (totalXOR == n) {
            for (int i = 1; i <= n; i++) ans.add(i);
        } else {
            int x = totalXOR ^ n;
            for (int i = 1; i <= n; i++) if (i != x) ans.add(i);
        }
        return ans;
    }
}

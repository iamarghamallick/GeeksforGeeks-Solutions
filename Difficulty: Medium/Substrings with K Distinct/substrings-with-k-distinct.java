class Solution {
    public int solve(String s , int k) {
        int i = 0;
        int j = 0;
        HashMap<Character, Integer> map = new HashMap<>();
        int n = s.length();
        int ans = 0;
        
        while(j < n) {
            map.put(s.charAt(j), map.getOrDefault(s.charAt(j), 0) + 1);
            while(map.size() > k) {
                map.put(s.charAt(i), map.getOrDefault(s.charAt(i), 0) - 1);
                if(map.get(s.charAt(i)) == 0)
                    map.remove(s.charAt(i));
                i++;
            }
            ans += (j - i + 1);
            j++;
        }
        
        return ans;
    }
    public int countSubstr(String s, int k) {
        return solve(s, k) - solve(s, k - 1);
    }
}
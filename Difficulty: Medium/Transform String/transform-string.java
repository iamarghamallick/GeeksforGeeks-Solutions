class Solution {
    int transform(String s1, String s2) {
        if(s1.length() != s2.length()) {
            return -1;
        }
        
        HashMap<Character, Integer> map = new HashMap<>();
        
        for(char ch: s1.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
        }
        
        for(char ch: s2.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) - 1);
        }
        
        for(Integer count: map.values()) {
            if(count != 0) {
                return -1;
            }
        }
        
        int steps = 0;
        
        int i = s1.length() - 1;
        int j = s2.length() - 1;
        
        while(i >= 0 && j >= 0) {
            if(s1.charAt(i) == s2.charAt(j)) {
                i--;
                j--;
            } else {
                steps++;
                i--;
            }
        }
        
        return steps;
    }
}
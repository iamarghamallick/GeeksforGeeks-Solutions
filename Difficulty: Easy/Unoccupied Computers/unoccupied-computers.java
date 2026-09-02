class Solution {
    public int solve(int n, String s) {
        HashSet<Character> assigned = new HashSet<>();
        HashSet<Character> notAssigned = new HashSet<>();
        
        for(char ch: s.toCharArray()) {
            if(notAssigned.contains(ch)) {
                continue;
            } else if(assigned.contains(ch)) {
                assigned.remove(ch);
                n++;
            } else if(n != 0) {
                assigned.add(ch);
                n--;
            } else {
                notAssigned.add(ch);
            }
        }
        
        return notAssigned.size();
    }
}

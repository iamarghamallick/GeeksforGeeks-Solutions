class Solution {
    public ArrayList<String> generateBinary(int n) {
        ArrayList<String> ans = new ArrayList<>();
        Queue<String> q = new LinkedList<>();
        q.add("1");
        while(n-- > 0) {
            String s1 = q.poll();
            ans.add(s1);
            String s2 = s1;
            if(q.size() < n) {
                q.add(s1 + "0");
                q.add(s2 + "1");
            }
        }
        return ans;
    }
}

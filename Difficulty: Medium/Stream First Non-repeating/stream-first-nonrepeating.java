class Solution {
    public String firstNonRepeating(String s) {
        int n = s.length();
        StringBuilder ans = new StringBuilder();
        int[] freq = new int[26]; // frequency of chars
        Queue<Character> q = new LinkedList<>();
        for(int i=0; i<n; i++){
            char ch = s.charAt(i);
            freq[ch-'a']++; // update freq
            q.offer(ch); // push to queue
            
            // remove from the front of q until we get non repeating char
            while(!q.isEmpty() && freq[q.peek()-'a']>1) q.poll();
            
            if(q.isEmpty()) ans.append('#'); // if we dont have any non repeating
            else ans.append(q.peek()); // append the non repeating char from front of q
        }
        return ans.toString();
    }
}
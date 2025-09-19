class Solution {
    public int minParentheses(String s) {
        int count = 0;
        Stack<Character> st = new Stack<>();
        for(int i=0; i<s.length(); i++) {
            if(s.charAt(i) == '(') st.push('(');
            else {
                if(!st.isEmpty() && st.peek() == '(') st.pop();
                else count++;
            }
        }
        return count + st.size();
    }
}

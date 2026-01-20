class Solution {
    StringBuilder sb=new StringBuilder();
    Stack<Character> stack=new Stack<>();
    
    public void append(char x) {
        // append x into document
        sb.append(x);
    }

    public void undo() {
        // undo last change
        int len=sb.length();
        stack.push(sb.charAt(len-1));
        sb.deleteCharAt(len-1);
    }

    public void redo() {
        // redo changes
        sb.append(stack.pop());
    }

    public String read() {
        // read the document
        return sb.toString();
    }
}

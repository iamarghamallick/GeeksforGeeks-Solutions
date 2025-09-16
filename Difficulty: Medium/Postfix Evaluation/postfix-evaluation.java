class Solution {
    private boolean isOperator(String s) {
        if(s.equals("+") || s.equals("-") || s.equals("*") ||
           s.equals("/") || s.equals("^"))
            return true;
        return false;
    }

    private int evaluate(int num1, String s, int num2) {
        switch(s) {
            case "+":
                return num1 + num2;
            case "-":
                return num1 - num2;
            case "*":
                return num1 * num2;
            case "/":
                return (int) Math.floor((double) num1 / num2);
            case "^":
                return (int) Math.pow(num1, num2);
        }
        return 0;
    }
    
    public int evaluatePostfix(String[] arr) {
        Stack<Integer> st = new Stack<>();
        
        for(String s : arr) {
            if(isOperator(s)) {
                int num2 = st.peek(); st.pop();
                int num1 = st.peek(); st.pop();
                int res = evaluate(num1, s, num2);
                st.push(res);
            } else {
                st.push(Integer.parseInt(s));
            }
        }
        
        return st.peek();
    }
}
class Solution {
    public static boolean checkRedundancy(String s) {
        Stack<Character> stack = new Stack<>();

        int i = 0;
        int n = s.length();

        while (i < n) {
            if (s.charAt(i) == ')') {
                boolean operatorFound = false;

                if (!stack.isEmpty() && stack.peek() == '(') {
                    return true;
                }

                while (!stack.isEmpty() && stack.peek() != '(') {
                    if (isOperator(stack.pop())) {
                        operatorFound = true;
                    }
                }

                if (!operatorFound) {
                    return true;
                }

                stack.pop(); // remove '('
            } else {
                stack.add(s.charAt(i));
            }
            i++;
        }

        if (stack.isEmpty() || containsValidCharacters(stack)) {
            return false;
        }

        return true;
    }
    
    private static boolean isOperator(Character c) {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    private static boolean containsValidCharacters(Stack<Character> stack) {
        for (Character c : stack) {
            if (c == '(') {
                return false;
            }
        }
        return true;
    }
}

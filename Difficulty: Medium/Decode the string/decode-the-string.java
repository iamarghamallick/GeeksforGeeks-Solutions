class Solution {
    static String decodeString(String s) {
        Stack<Integer> countStack = new Stack<>();
        Stack<StringBuilder> strStack = new Stack<>();
        StringBuilder currStr = new StringBuilder();
        int k = 0;

        for (char c : s.toCharArray()) {
            if (Character.isDigit(c)) {
                k = k * 10 + (c - '0'); // build number
            } else if (c == '[') {
                countStack.push(k);
                strStack.push(currStr);
                k = 0;
                currStr = new StringBuilder();
            } else if (c == ']') {
                int count = countStack.pop();
                StringBuilder prevStr = strStack.pop();
                for (int i = 0; i < count; i++) {
                    prevStr.append(currStr);
                }
                currStr = prevStr;
            } else {
                currStr.append(c);
            }
        }

        return currStr.toString();
    }
}
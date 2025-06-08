class Solution {
  public:
    // Adds two numeric strings and returns
    // the sum as string
    string addStrings(string num1, string num2) {
        if (num1.length() < num2.length()) {
            swap(num1, num2);
        }

        int len1 = num1.length();
        int len2 = num2.length();
        string sum = "";
        int carry = 0;

        // Add from least significant digits
        for (int i = 0; i < len2; i++) {
            int d1 = num1[len1 - 1 - i] - '0';
            int d2 = num2[len2 - 1 - i] - '0';
            int digit = (d1 + d2 + carry) % 10;
            carry = (d1 + d2 + carry) / 10;
            sum = char(digit + '0') + sum;
        }

        // Add remaining digits of num1
        for (int i = len2; i < len1; i++) {
            int d = num1[len1 - 1 - i] - '0';
            int digit = (d + carry) % 10;
            carry = (d + carry) / 10;
            sum = char(digit + '0') + sum;
        }

        // Add remaining carry
        if (carry) {
            sum = char(carry + '0') + sum;
        }

        return sum;
    }

    // Recursively checks if the string from index
    // start is a valid sum-sequence
    bool checkSequence(string s, int start, int len1, int len2) {

        string part1 = s.substr(start, len1);
        string part2 = s.substr(start + len1, len2);
        string expectedSum = addStrings(part1, part2);

        int sumLen = expectedSum.length();

        // If sum length exceeds remaining string,
        // return false
        if (start + len1 + len2 + sumLen > s.length()) {
            return false;
        }

        // If the sum matches the next part in string
        if (expectedSum == s.substr(start + len1 + len2, sumLen)) {

            // If end is reached, return true
            if (start + len1 + len2 + sumLen == s.length()) {
                return true;
            }

            // Recur for next pair: part2 and expectedSum
            return checkSequence(s, start + len1, len2, sumLen);
        }

        // Sum does not match the next segment
        return false;
    }

    // Function to check if a string is a sum-string
    bool isSumString(string s) {
        int n = s.length();

        // Try all combinations of first two parts
        for (int len1 = 1; len1 < n; len1++) {
            for (int len2 = 1; len1 + len2 < n; len2++) {
                if (checkSequence(s, 0, len1, len2)) {
                    return true;
                }
            }
        }

        return false;
    }
};
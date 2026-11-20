class Solution {
	public int minFlips(String s) {
		int count = 0;
		char expected = '0';
		for (char ch: s.toCharArray()) {
			if (ch != expected) {
				count++;
			}
			expected = expected == '0' ? '1' : '0';
		}
		return Math.min(count, s.length() - count);
	}
}

class Solution {
	public String findRollOut(String s, int[] roll) {
		int n = s.length();
		
		int[] diff = new int[n + 1];
		
		for (int i = 0; i<roll.length; i++) {
			diff[0]++;
			diff[roll[i]]--;
		}
		
		for (int i = 1; i<n; i++) {
			diff[i] += diff[i - 1];
		}
		
		char[] chars = s.toCharArray();
		
		for (int i = 0; i < n; i++) {
			chars[i] = (char) ('a' + ((chars[i] - 'a') + (diff[i] % 26)) % 26);
		}
		
		return new String(chars);
	}
}

class Solution {
	public String lexiString(String s) {
		int n = s.length();
		String doubled = s + s;
		
		int i = 0, j = 1, k = 0;
		
		while (i < n && j < n && k < n) {
			char a = doubled.charAt(i + k);
			char b = doubled.charAt(j + k);
			
			// If characters are equal, continue comparing
			if (a == b) {
				k++;
				continue;
			}
			
			// Discard the lexicographically larger rotation
			if (a > b) {
				i = i + k + 1;
			} else {
				j = j + k + 1;
			}
			
			// Avoid comparing the same candidate
			if (i == j) {
				j++;
			}
			
			// Reset matched characters
			k = 0;
		}
		
		// Get the starting index of smallest rotation
		int idx = Math.min(i, j);
		
		return doubled.substring(idx, idx + n);
	}
}

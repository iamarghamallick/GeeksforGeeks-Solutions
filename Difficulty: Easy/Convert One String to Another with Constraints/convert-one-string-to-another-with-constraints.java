class Solution {
	public boolean isItPossible(String s1, String s2) {
		int m = s1.length();
		int n = s2.length();
		
		if (m != n)
			return false;
		
		int i = 0, j = 0;
		
		while (i < m || j < n) {
			
			// skip '#' characters in both strings
			while (i < m && s1.charAt(i) == '#')
				i++;
			while (j < n && s2.charAt(j) == '#')
				j++;
			
			// both strings have ended: every character matched successfully
			if (i >= m && j >= n)
				break;
			
			// only one string has ended: the counts of non-'#' characters differ
			if (i >= m || j >= n)
				return false;
			
			// characters must match in identity and relative sequence order
			if (s1.charAt(i) != s2.charAt(j))
				return false;
			
			// 'A' can only move left, so its s2 position must not exceed its s1 position
			if (s1.charAt(i) == 'A' && i < j)
				return false;
			
			// 'B' can only move right, so its s2 position must not be less than its s1 position
			if (s1.charAt(i) == 'B' && i > j)
				return false;
			
			i++;
			j++;
		}
		
		return true;
	}
};

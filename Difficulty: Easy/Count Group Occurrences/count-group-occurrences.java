class Solution {
	int getCount(String s, int k) {
		int n = s.length();
		int[] freq = new int[26];
		int i = 0;
		
		// Count groups of consecutive identical characters
		while (i < n) {
			int j = i;
			
			// Find the end of the current group
			while (j < n && s.charAt(j) == s.charAt(i)) {
				j++;
			}
			
			// Increment the group count of the character
			freq[s.charAt(i) - 'a']++;
			
			// Move to the next group
			i = j;
		}
		
		int res = 0;
		
		// Count characters having exactly k groups
		for (int x = 0; x < 26; x++) {
			if (freq[x] == k) {
				res++;
			}
		}
		
		return res;
	}
}

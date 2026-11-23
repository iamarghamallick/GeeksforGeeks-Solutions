class Solution {
	public char posInfinite(String s, int pos) {
		int n = s.length();
		
		long len = n;
		int step = 1;
		
		// Find the construction level containing pos.
		while (len < pos) {
			len = 2 * len + step;
			step++;
		}
		
		// Work backwards through the levels.
		while (step > 1) {
			long prevLen = (len - (step - 1)) / 2;
			
			// Position lies in the newly inserted '$'
			// characters.
			if (pos > prevLen && pos <= prevLen + step - 1)
				return '$';
			
			if (pos <= prevLen) {
				// Position belongs to the previous string.
				len = prevLen;
			}
			else {
				// Position belongs to reverse(previous
				// string).
				pos = (int)(len - pos + 1);
				len = prevLen;
			}
			
			step--;
		}
		
		// Position is inside the original string.
		return s.charAt(pos - 1);
		
		// 		int i = 1;
		
		// 		while (s.length() < pos) {
		// 			StringBuilder rev = new StringBuilder(s);
		// 			rev.reverse();
		// 			s += "$".repeat(i) + rev.toString();
		// 			i++;
		// 		}
		
		// 		return s.charAt(pos - 1);
	}
}

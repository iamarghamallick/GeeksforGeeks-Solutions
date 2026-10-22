class Solution {
	public int minimumSum(String s) {
		if (!isPossible(s))
			return - 1;
		
		int n = s.length();
		char[] sArray = s.toCharArray();
		
		// Copy known characters to their symmetric '?'
		// positions.
		for (int i = 0; i < n / 2; i++) {
			if (sArray[i] == '?'
			 && sArray[n - i - 1] != '?')
			sArray[i] = sArray[n - i - 1];
			else if (sArray[i] != '?'
			 && sArray[n - i - 1] == '?')
			sArray[n - i - 1] = sArray[i];
		}
		
		ArrayList<Character> st = new ArrayList<>();
		
		// Fill consecutive '?' using the nearest known
		// character on the left.
		for (int i = 0; i < n;) {
			if (sArray[i] != '?') {
				st.add(sArray[i]);
				i++;
			}
			else {
				if (!st.isEmpty()) {
					while (i < n && sArray[i] == '?')
						sArray[i++] = st.get(st.size() - 1);
					st.remove(st.size() - 1);
				}
				else {
					i++;
				}
			}
		}
		
		st.clear();
		
		// Fill remaining '?' using the nearest known
		// character on the right.
		for (int i = n - 1; i >= 0;) {
			if (sArray[i] != '?') {
				st.add(sArray[i]);
				i--;
			}
			else {
				if (!st.isEmpty()) {
					while (i >= 0 && sArray[i] == '?')
						sArray[i--] = st.get(st.size() - 1);
					st.remove(st.size() - 1);
				}
				else {
					i--;
				}
			}
		}
		
		// If any '?' still remain, replace them with 'a'.
		for (int i = 0; i < n; i++) {
			if (sArray[i] == '?')
				sArray[i] = 'a';
		}
		
		// Compute the sum of absolute differences of
		// adjacent characters.
		int res = 0;
		for (int i = 0; i + 1 < n; i++)
			res += Math.abs((sArray[i] - 'a')
		- (sArray[i + 1] - 'a'));
		
		return res;
	}
	
	private boolean isPossible(String s) {
		int n = s.length();
		for (int i = 0; i < n / 2; i++) {
			if (s.charAt(i) != '?'
			 && s.charAt(n - i - 1) != '?'
			 && s.charAt(i) != s.charAt(n - i - 1))
			return false;
		}
		return true;
	}
}

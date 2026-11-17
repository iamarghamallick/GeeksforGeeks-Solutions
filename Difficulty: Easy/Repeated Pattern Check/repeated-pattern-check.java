class Solution {
	public boolean findPattern(String s) {
		char prev = 'y';
		int flag = 0;
		
		for (char ch: s.toCharArray()) {
			if (ch == 'x') {
				flag++;
			} else {
				flag--;
			}
			
			if (ch == 'x' && ch != prev && flag != 1) {
				return false;
			}
			
			prev = ch;
		}
		
		return flag == 0;
	}
}

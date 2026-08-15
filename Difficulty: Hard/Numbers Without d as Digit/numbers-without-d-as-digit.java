class Solution {
	public int countWithout(int n, int d) {
		if (n == 0) {
			return 0;
		}
		
		String s = String.valueOf(n);
		int k = s.length();
		int ans = 0;
		
		for (int i = 1; i <= k - 1; i++) {
			if (d == 0) {
				ans += 9 * (int) Math.pow(9, i - 1);
			} else {
				ans += 8 * (int) Math.pow(9, i - 1);
			}
		}
		
		for (int i = 0; i < k; i++) {
			int curr = s.charAt(i) - '0';
			int remaining = k - i - 1;
			
			int choices;
			
			if (i == 0) {
				choices = curr - 1;
				if (d != 0 && d < curr) {
					choices--;
				}
			} else {
				choices = curr;
				if (d < curr) {
					choices--;
				}
			}
			
			ans += choices * (int) Math.pow(9, remaining);
			
			if (curr == d) {
				return (int) ans;
			}
		}
		
		return (int) ans + 1;
	}
}

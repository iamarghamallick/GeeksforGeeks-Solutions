class Solution {
	
	int MOD = 1_000_000_007;
	
	public int palindromicStrings(int n, int k) {
		long ans = 0, fact = k;
		
		for (int i = 0; i < n / 2; i++) {
			ans = (ans + fact) % MOD;
			fact = (fact * (k - i - 1)) % MOD;
		}
		
		if (n % 2 == 1) {
			return (int) ((2 * ans + fact) % MOD);
		}
		
		return (int) ((2 * ans) % MOD);
	}
}

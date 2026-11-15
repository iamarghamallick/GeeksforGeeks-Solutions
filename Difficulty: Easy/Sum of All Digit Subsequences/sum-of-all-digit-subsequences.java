class Solution {
	
	private final int MOD = 1000000007;
	
	public int subsequenceSum(String s) {
		int n = s.length();
		long sum = 0;
		
		for (char ch : s.toCharArray()) {
			sum = (sum + ch - '0') % MOD;
		}
		
		long freq = 1;
		
		for (int i = 1; i < n; i++) {
			freq = (freq * 2) % MOD;
		}
		
		return (int)((sum * freq) % MOD);
	}
}

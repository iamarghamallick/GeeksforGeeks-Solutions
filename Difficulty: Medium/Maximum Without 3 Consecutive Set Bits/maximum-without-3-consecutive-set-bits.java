class Solution {
	public int maxValue(int n) {
		int ans = n;
		
		for (int i = 30; i >= 2; --i) {
			if ((ans & (1 << i)) != 0
			 && (ans & (1 << (i - 1))) != 0
			 && (ans & (1 << (i - 2))) != 0) {
				
				ans &= ~(1 << (i - 2));
			}
		}
		
		return ans;
	}
}

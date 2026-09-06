class Solution {
	public long pairAndSum(int[] arr) {
		int n = arr.length;
		long ans = 0;
		
		for (int i = 0; i<32; i++) {
			int k = 0;
			
			for (int j = 0; j<n; j++) {
				if ((arr[j] & (1 << i)) != 0) {
					k++;
				}
			}
			
			ans += (1L << i) * ((long) k * (k - 1) / 2);
		}
		
		return ans;
	}
}

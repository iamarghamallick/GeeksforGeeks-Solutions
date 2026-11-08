class Solution {
	public int minTime(int n, int s1, int s2) {
		if (s1 > s2) {
			int temp = s1;
			s1 = s2;
			s2 = temp;
		}
		
		int ans = Integer.MAX_VALUE;
		int low = 0;
		int high = n;
		
		while (low <= high) {
			int mid = low + (high - low) / 2;
			
			int t1 = mid * s1;
			int t2 = (n - mid) * s2;
			
			ans = Math.min(ans, Math.max(t1, t2));
			
			if (t1 <= t2) {
				low = mid + 1;
			} else {
				high = mid - 1;
			}
		}
		
		return ans;
	}
}

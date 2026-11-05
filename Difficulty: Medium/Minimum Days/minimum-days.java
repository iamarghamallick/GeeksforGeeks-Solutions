class Solution {
	public int getMinimumDays(String s, int[] p) {
		int n = s.length();
		char[] arr = s.toCharArray();
		HashSet<Integer> set = new HashSet<>();
		
		for (int i = 1; i<n; i++) {
			if (arr[i - 1] == arr[i]) {
				set.add(i - 1);
			}
		}
		
		if (set.isEmpty()) {
			return 0;
		}
		
		for (int day = 0; day<p.length; day++) {
			int idx = p[day];
			
			if (idx - 1 >= 0) {
				set.remove(idx - 1);
			}
			
			if (idx < n - 1) {
				set.remove(idx);
			}
			
			arr[idx] = '?';
			
			if (set.isEmpty()) {
				return day + 1;
			}
		}
		
		return n;
	}
}

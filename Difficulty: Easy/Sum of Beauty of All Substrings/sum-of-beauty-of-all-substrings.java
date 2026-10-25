class Solution {
	public int beautySum(String s) {
		int sum = 0;
		int n = s.length();
		
		for (int i = 0; i<n; i++) {
			int[] freq = new int[26];
			
			for (int j = i; j<n; j++) {
				freq[s.charAt(j) - 'a']++;
				
				int mini = Integer.MAX_VALUE;
				int maxi = Integer.MIN_VALUE;
				
				for (int k = 0; k<26; k++) {
					if (freq[k] > 0) {
						mini = Math.min(mini, freq[k]);
						maxi = Math.max(maxi, freq[k]);
					}
				}
				
				sum += maxi - mini;
			}
		}
		
		return sum;
	}
}

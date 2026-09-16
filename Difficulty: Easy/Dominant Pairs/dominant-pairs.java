class Solution {
	public int dominantPairs(int[] arr) {
		int n = arr.length;
		int count = 0;
		
		Arrays.sort(arr, 0, n/2);
		Arrays.sort(arr, n/2, n);
		
		for (int i = 0; i<n/2; i++) {
			int j = n/2;
			for (; j<n; j++) {
				if (arr[i] < 5 * arr[j]) {
					break;
				}
			}
			count += (j - n/2);
		}
		
		return count;
	}
}

class Solution {
	public int maximumSubarray(int[] arr) {
		int n = arr.length;
		int[] left = new int[n];
		int[] right = new int[n];
		
		int maxi = 0;
		
		for (int i = 0; i<n; i++) {
			maxi += arr[i];
			
			if (maxi < 0) {
				maxi = 0;
			}
			
			left[i] = maxi;
		}
		
		maxi = 0;
		
		for (int i = n - 1; i >= 0; i--) {
			maxi += arr[i];
			
			if (maxi < 0) {
				maxi = 0;
			}
			
			right[i] = maxi;
		}
		
		int ans = 0;
		
		for (int i = 0; i<n; i++) {
			ans = Math.max(ans,
        			(i > 0 ? left[i - 1] : 0) +
        			arr[i] * arr[i] +
        			(i < n - 1 ? right[i + 1] : 0)
    			);
		}
		
		return ans;
	}
}

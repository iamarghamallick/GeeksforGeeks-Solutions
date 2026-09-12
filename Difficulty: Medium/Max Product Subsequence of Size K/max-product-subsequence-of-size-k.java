class Solution {
	public int maxProduct(int[] arr, int k) {
		int n = arr.length;
		int prod = 1;
		
		Arrays.sort(arr);
		
		int max = arr[n - 1];
		
		// case 1: max is 0 and k is Odd
		if (max == 0 && k % 2 != 0) {
			return 0;
		}
		
		// case 2: max is < 0 and k is Odd
		if (max < 0 && k % 2 != 0) {
			for (int i = n - 1; i>=n - k; i--) {
				prod *= arr[i];
			}
			
			return prod;
		}
		
		// case 3: max is > 0 and k is Odd
		int left = 0;
		int right = n - 1;
		
		if (max > 0 && k % 2 != 0) {
			prod = arr[right];
			right--;
			k--;
		}
		
		// case 4: k is even
		k = k/2;
		
		for (int i = 0; i<k; i++) {
			int c1 = arr[left] * arr[left + 1];
			int c2 = arr[right] * arr[right - 1];
			
			if (c1 >= c2) {
				prod *= c1;
				left += 2;
			} else {
				prod *= c2;
				right -= 2;
			}
		}
		
		return prod;
	}
}

// TLE

// class Solution {
// 	public int maxProduct(int[] arr, int k) {
// 		return solve(0, k, arr, 1);
// 	}

// 	private int solve(int i, int k, int[] arr, int prod) {
// 		if (k == 0) {
// 			return prod;
// 		}

// 		if (i == arr.length) {
// 			return Integer.MIN_VALUE;
// 		}

// 		int take = solve(i + 1, k - 1, arr, arr[i] * prod);
// 		int notTake = solve(i + 1, k, arr, prod);

// 		return Math.max(take, notTake);
// 	}
// }

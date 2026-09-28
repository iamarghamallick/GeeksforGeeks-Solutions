class Solution {
	// Function to compute GCD of two numbers
	static int gcd(int a, int b) {
		if (b == 0)
			return a;
		return gcd(b, a % b);
	}
	
	// Get mid index
	static int getMid(int s, int e) {
		return s + (e - s) / 2;
	}
	
	// Build segment tree
	static int buildSegmentTree(int[] arr, int ss, int se, int[] st, int si) {
		if (ss == se) {
			st[si] = arr[ss];
			return arr[ss];
		}
		int mid = getMid(ss, se);
		st[si] = gcd(
		buildSegmentTree(arr, ss, mid, st, si * 2 + 1),
		buildSegmentTree(arr, mid + 1, se, st, si * 2 + 2));
		return st[si];
	}
	
	// Query GCD in range
	static int findGcd(int ss, int se, int qs, int qe,
	int si, int[] st) {
		if (ss > qe || se < qs)
			return 0; // neutral for GCD
		if (qs <= ss && qe >= se)
			return st[si];
		int mid = getMid(ss, se);
		return gcd(
		findGcd(ss, mid, qs, qe, 2 * si + 1, st),
		findGcd(mid + 1, se, qs, qe, 2 * si + 2, st));
	}
	
	// Update a value in segment tree
	static void updateValueUtil(int ss, int se, int index,
	int new_val, int si, int[] st) {
		if (index < ss || index > se)
			return;
		if (ss == se) {
			st[si] = new_val;
			return;
		}
		int mid = getMid(ss, se);
		if (index <= mid)
			updateValueUtil(ss, mid, index, new_val,
		2 * si + 1, st);
		else
			updateValueUtil(mid + 1, se, index, new_val,
		2 * si + 2, st);
		st[si] = gcd(st[2 * si + 1], st[2 * si + 2]);
	}
	
	// Wrapper to update value
	static void updateValue(int index, int new_val,
	int[] arr, int[] st, int n) {
		arr[index] = new_val;
		updateValueUtil(0, n - 1, index, new_val, 0, st);
	}
	
	// Process queries
	static ArrayList<Integer> processQueries(int[] arr, int[][] q) {
		int n = arr.length;
		int x = 2 * (int)Math.pow(2, Math.ceil(Math.log(n) / Math.log(2))) - 1;
		int[] st = new int[x];
		buildSegmentTree(arr, 0, n - 1, st, 0);
		
		ArrayList<Integer> result = new ArrayList<>();
		for (int i = 0; i < q.length; i++) {
			int type = q[i][0];
			if (type == 1) {
				int index = q[i][1];
				int new_val = q[i][2];
				updateValue(index, new_val, arr, st, n);
			}
			else {
				int l = q[i][1];
				int r = q[i][2];
				result.add(findGcd(0, n - 1, l, r, 0, st));
			}
		}
		return result;
	}
}

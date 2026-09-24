class Solution {
	static class FenwickTree {
		int[] tree;
		
		FenwickTree(int n) {
			tree = new int[n + 1];
		}
		
		void update(int index, int value) {
			while (index < tree.length) {
				tree[index] = Math.max(tree[index], value);
				index += index & -index;
			}
		}
		
		int query(int index) {
			int result = 0;
			
			while (index > 0) {
				result = Math.max(result, tree[index]);
				index -= index & -index;
			}
			
			return result;
		}
	}
	
	public int maxStackHeight(int[] r, int[] h) {
		int n = r.length;
		
		int[][] discs = new int[n][2];
		
		for (int i = 0; i < n; i++) {
			discs[i][0] = r[i];
			discs[i][1] = h[i];
		}
		
		// Equal radii are sorted by height in descending order.
		Arrays.sort(discs, (a, b) -> {
			if (a[0] != b[0])
				return Integer.compare(a[0], b[0]);
			
			return Integer.compare(b[1], a[1]);
		});
		
		int[] heights = new int[n];
		
		for (int i = 0; i < n; i++)
			heights[i] = h[i];
		
		Arrays.sort(heights);
		
		int uniqueCount = 0;
		
		for (int height : heights) {
			if (uniqueCount == 0 || heights[uniqueCount - 1] != height)
				heights[uniqueCount++] = height;
		}
		
		FenwickTree bit = new FenwickTree(uniqueCount);
		
		int ans = 0;
		
		for (int[] disc : discs) {
			int height = disc[1];
			
			int index = Arrays.binarySearch(
			heights, 0, uniqueCount, height
			) + 1;
			
			// Query only strictly smaller heights.
			int best = bit.query(index - 1);
			
			int currentHeight = best + height;
			
			bit.update(index, currentHeight);
			
			ans = Math.max(ans, currentHeight);
		}
		
		return ans;
	}
}

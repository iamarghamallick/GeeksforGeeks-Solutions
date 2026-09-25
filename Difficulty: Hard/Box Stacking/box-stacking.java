class Solution {
	static int maxHeightRecur(int i, int[][] boxes, int[] dp) {
		// If value is stored in dp array
		if (dp[i] != -1)
			return dp[i];
		
		int ans = boxes[i][2];
		
		// Check all the boxes that can be placed above box i
		for (int j = i + 1; j < boxes.length; j++) {
			
			// If dimensions of box j are less
			// than that size of box i
			if (boxes[i][0] > boxes[j][0] && boxes[i][1] > boxes[j][1]) {
				ans = Math.max(ans, boxes[i][2] + maxHeightRecur(j, boxes, dp));
			}
		}
		
		return dp[i] = ans;
	}
	
	static int maxHeight(int[] height, int[] width, int[] length) {
		int n = height.length;
		
		// Create a 2d array to store all
		// orientations of boxes in (l, b, h)
		// manner.
		int[][] boxes = new int[n * 6][3];
		int idx = 0;
		
		for (int i = 0; i < n; i++) {
			int a = height[i], b = width[i], c = length[i];
			
			boxes[idx++] = new int[] {a, b, c};
			boxes[idx++] = new int[] {a, c, b};
			boxes[idx++] = new int[] {b, a, c};
			boxes[idx++] = new int[] {b, c, a};
			boxes[idx++] = new int[] {c, a, b};
			boxes[idx++] = new int[] {c, b, a};
		}
		
		// Sort the boxes in descending
		// order of length and width.
		Arrays.sort(boxes, (box1, box2) -> {
			if (box1[0] == box2[0]) {
				if (box1[1] == box2[1])
					return Integer.compare(box1[2], box1[2]);
				else
					return Integer.compare(box2[1], box1[1]);
			}
			return Integer.compare(box2[0], box1[0]);
		});
		
		int[] dp = new int[boxes.length];
		Arrays.fill(dp, -1);
		
		int ans = 0;
		
		// Check for all boxes starting as base.
		for (int i = 0; i < boxes.length; i++) {
			ans = Math.max(ans, maxHeightRecur(i, boxes, dp));
		}
		
		return ans;
	}
}

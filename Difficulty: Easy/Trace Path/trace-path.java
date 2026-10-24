class Solution {
	public boolean isPossible(int n, int m, String s) {
		int i = 0, j = 0;
		int maxR = 0, minR = 0;
		int maxC = 0, minC = 0;
		
		for (char c: s.toCharArray()) {
			switch (c) {
				case 'L' -> j--;
				case 'R' -> j++;
				case 'D' -> i--;
				case 'U' -> i++;
			}
			
			maxR = Math.max(maxR, i);
			minR = Math.min(minR, i);
			maxC = Math.max(maxC, j);
			minC = Math.min(minC, j);
		}
		
		int height = maxR - minR + 1;
		int width = maxC - minC + 1;
		
		return height <= n && width <= m;
	}
}

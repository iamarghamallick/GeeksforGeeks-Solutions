class Solution {
	public int sameMod(int[] arr) {
		int n = arr.length;
		int g = 0;
		
		for (int i = 1; i<n; i++) {
			g = gcd(g, Math.abs(arr[i] - arr[0]));
		}
		
		if (g == 0) {
			return - 1;
		}
		
		int count = 0;
		
		for (int i = 1; i*i <= g; i++) {
			if (g % i == 0) {
				count++;
				
				if (i != g / i) {
					count++;
				}
			}
		}
		
		return count;
	}
	
	private int gcd(int a, int b) {
		if (b == 0) {
			return a;
		}
		
		return gcd(b, a % b);
	}
}

class Solution {
	public char nthCharacter(int n) {
		int len = 1;
		long count = 9;
	    long start = 1;
		
		while (n > len * count) {
			n -= len * count;
			len++;
			count *= 10;
			start *= 10;
		}
		
		long num = start + (n - 1) / len;
		int digitIndex = (n - 1) % len;
		long divisor = 1;
		
		for (int i = 0; i < len - digitIndex - 1; i++) {
			divisor *= 10;
		}
		
		int digit = (int)(num / divisor) % 10;
		
		return (char)('0' + digit);
	}
}

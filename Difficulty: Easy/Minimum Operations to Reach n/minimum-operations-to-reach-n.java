class Solution {
	public int minOperation(int n) {
		int count = 0;
		
		while (n != 0) {
			if (n % 2 == 0) {
				n /= 2;
				count++;
			} else {
				n--;
				count++;
				if (n > 0) {
					n /= 2;
					count++;
				}
			}
		}
		
		return count;
	}
}

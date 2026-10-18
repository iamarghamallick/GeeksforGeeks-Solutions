class Solution {
	public int minimumStep(int n) {
		int step = 0;
		
		while (n>1) {
			if (n%3 == 0)
				n /= 3;
			else
				n--;
			step++;
		}
		
		return step;
	}
}

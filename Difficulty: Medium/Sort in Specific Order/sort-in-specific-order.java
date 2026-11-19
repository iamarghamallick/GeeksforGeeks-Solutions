class Solution {
	public void sortIt(int[] arr) {
		int[] sorted = Arrays.stream(arr)
        		.boxed()
        		.sorted((a, b) -> {
        			boolean aEven = (a % 2 == 0);
        			boolean bEven = (b % 2 == 0);
        			
        			if (aEven && bEven) {
        				return a - b;
        			} else if (!aEven && !bEven) {
        				return b - a;
        			} else {
        				return aEven ? 1 : -1;
        			}
        		})
        		.mapToInt(Integer::intValue)
        		.toArray();
		
		System.arraycopy(sorted, 0, arr, 0, arr.length);
	}
}

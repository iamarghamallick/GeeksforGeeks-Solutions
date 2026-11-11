class Solution {
	public boolean checkWithinK(int[] arr, int k) {
		HashMap<Integer, Integer> map = new HashMap<>();
		
		for (int j = 0; j<arr.length; j++) {
			int i = map.getOrDefault(arr[j], -1);
			if (i != -1 && j - i <= k) {
				return true;
			}
			map.put(arr[j], j);
		}
		
		return false;
	}
}

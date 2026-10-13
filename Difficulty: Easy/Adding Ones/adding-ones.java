class Solution {
	public ArrayList<Integer> update(int n, int[] updates) {
		int[] arr = new int[n];
		
		for (int j: updates) {
			arr[j - 1]++;
		}
		
		for (int i=1; i<n; i++) {
			arr[i] += arr[i - 1];
		}
		
		return new ArrayList<>(Arrays.stream(arr).boxed().toList());
	}
}

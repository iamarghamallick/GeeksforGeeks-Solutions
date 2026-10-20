class Solution {
	public ArrayList<Integer> lexicographicallyLargest(int[] arr) {
		int n = arr.length;
		int i = 0;
		
		while (i < n) {
			int j = i + 1;
			
			while (j < n && arr[j] % 2 == arr[j - 1] % 2)
				j++;
			
			Arrays.sort(arr, i, j);
			
			for (int left = i, right = j - 1; left < right;
			left++, right--) {
				int temp = arr[left];
				arr[left] = arr[right];
				arr[right] = temp;
			}
			
			i = j;
		}
		
		ArrayList<Integer> ans = new ArrayList<>();
		
		for (int x : arr)
			ans.add(x);
		
		return ans;
	}
}

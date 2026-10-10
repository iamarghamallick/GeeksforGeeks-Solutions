class Solution {
	public void mergeTwoParts(int[] arr) {
		int n = arr.length;
		
		int index = 0;
		
		int[] temp = new int[n];
		
		for (int i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				index = i + 1;
				break;
			}
		}
		
		if (index == 0) {
			return;
		}
		
		int i = 0, j = index, k = 0;
		
		while (i < index && j < n) {
			if (arr[i] < arr[j])
				temp[k++] = arr[i++];
			else
				temp[k++] = arr[j++];
		}
		
		while (i < index)
			temp[k++] = arr[i++];
		
		while (j < n)
			temp[k++] = arr[j++];
		
		for (int l = 0; l < n; l++) {
			arr[l] = temp[l];
		}
	}
}

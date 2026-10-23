/* BST Node Structure
class Node {
	int data;
	Node left, right;
	
	Node(int val) {
		data = val;
		left = right = null;
	}
}
*/

class Solution {
	int count;
	
	public int pairsViolatingBST(Node root) {
		count = 0;
		ArrayList<Integer> arr = new ArrayList<>();
		inorder(root, arr);
		mergeSort(arr, 0, arr.size() - 1);
		return count;
	}
	
	private void mergeSort(ArrayList<Integer> arr, int left, int right) {
		if (left >= right) {
			return;
		}
		
		int mid = left + (right - left) / 2;
		
		mergeSort(arr, left, mid);
		mergeSort(arr, mid + 1, right);
		merge(arr, left, mid, right);
	}
	
	private void merge(ArrayList<Integer> arr, int left, int mid, int right) {
		int[] temp = new int[right - left + 1];
		int i = left, j = mid + 1, k = 0;
		
		while (i <= mid && j <= right) {
			if (arr.get(i) <= arr.get(j)) {
				temp[k] = arr.get(i);
				k++; i++;
			} else {
				count += mid - i + 1;
				temp[k] = arr.get(j);
				k++; j++;
			}
		}
		
		while (i <= mid) {
			temp[k] = arr.get(i);
			k++; i++;
		}
		
		while (j <= right) {
			temp[k] = arr.get(j);
			k++; j++;
		}
		
		for (i = left, k = 0; i <= right; i++, k++) {
			arr.set(i, temp[k]);
		}
	}
	
	private void inorder(Node root, ArrayList<Integer> arr) {
		if (root == null) {
			return;
		}
		
		inorder(root.left, arr);
		arr.add(root.data);
		inorder(root.right, arr);
	}
}

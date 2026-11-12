/* Structure of a Binary Search Tree node
class Node {
	int data;
	Node left, right;
	
	public Node(int val) {
		data = val;
		left = right = null;
	}
}
*/

class Solution {
	
	private int ans = Integer.MAX_VALUE;
	
	public int minDiff(Node root, int k) {
		if (k == root.data) {
			return 0;
		}
		
		if (k > root.data && root.right != null) {
			ans = Math.min(ans, Math.abs(root.data - k));
			return minDiff(root.right, k);
		}
		
		if (k < root.data && root.left != null) {
			ans = Math.min(ans, Math.abs(root.data - k));
			return minDiff(root.left, k);
		}
		
		return ans = Math.min(ans, Math.abs(root.data - k));
	}
}

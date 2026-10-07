/* Node Structure
class Node
{
	int data;
	Node left, right;
	
	Node(int item)
	{
		data = item;
		left = right = null;
	}
} */
class Solution {
	public int maxPathSum(Node root) {
		int[] maxSum = new int[] { Integer.MIN_VALUE };
		
		solve(root, maxSum);
		
		return maxSum[0] == Integer.MIN_VALUE ? -1 : maxSum[0];
	}
	
	private int solve(Node root, int[] maxSum) {
		if (root == null) {
			return 0;
		}
		
		if (root.left == null && root.right == null) {
			return root.data;
		}
		
		int leftPathSum = solve(root.left, maxSum);
		int rightPathSum = solve(root.right, maxSum);
		
		if (root.left != null && root.right != null) {
			maxSum[0] = Math.max(maxSum[0], leftPathSum + rightPathSum + root.data);
			return Math.max(leftPathSum, rightPathSum) + root.data;
		}
		
		if (root.left != null) {
			return leftPathSum + root.data;
		}
		
		return rightPathSum + root.data;
	}
}

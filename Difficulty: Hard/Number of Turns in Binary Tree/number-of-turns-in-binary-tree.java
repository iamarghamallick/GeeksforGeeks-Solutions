/* Structure of Binary Tree Node
class Node {
	int data;
	Node left;
	Node right;
	
	Node(int val) {
		data = val;
		left = right = null;
	}
} */

class Solution {
	
	enum Directions {
		LEFT, RIGHT
	}
	
	private Node findLCA(Node root, int x, int y) {
	    
		if (root == null) {
			return null;
		}
		
		if (root.data == x || root.data == y) {
			return root;
		}
		
		Node leftLCA = findLCA(root.left, x, y);
		Node rightLCA = findLCA(root.right, x, y);
		
		if (leftLCA != null && rightLCA != null) {
			return root;
		}
		
		return leftLCA != null ? leftLCA : rightLCA;
	}
	
	private int findTurns(Node root, int key, Directions prevDirection) {
		
		if (root == null) {
			return - 1;
		}
		
		if (root.data == key) {
			return 0;
		}
		
		if (prevDirection == null) {
			int leftTurns = findTurns(root.left, key, Directions.LEFT);
			int rightTurns = findTurns(root.right, key, Directions.RIGHT);
			
			if (leftTurns != -1) {
				return leftTurns;
			}
			else if (rightTurns != -1) {
				return rightTurns;
			}
			else {
				return - 1;
			}
		} else if (prevDirection == Directions.LEFT) {
			int leftTurns = findTurns(root.left, key, prevDirection);
			int rightTurns = findTurns(root.right, key, Directions.RIGHT);
			
			if (leftTurns != -1) {
				return leftTurns;
			}
			else if (rightTurns != -1) {
				return 1 + rightTurns;
			}
			else {
				return - 1;
			}
		} else {
			int leftTurns = findTurns(root.left, key, Directions.LEFT);
			int rightTurns = findTurns(root.right, key, prevDirection);
			
			if (leftTurns != -1) {
				return 1 + leftTurns;
			}
			else if (rightTurns != -1) {
				return rightTurns;
			}
			else {
				return - 1;
			}
		}
		
	}
	
	public int numberOfTurns(Node root, int p, int q) {
		
		// Find LCA of the binary tree
		Node lca = findLCA(root, p, q);
		
		// System.out.println("LCA = " + lca.data);
		
		// Calculate turns
		int pTurns = findTurns(lca, p, null);
		int qTurns = findTurns(lca, q, null);
		
		int totalTurns = pTurns + qTurns;
		
		if (lca.data != p && lca.data != q)
			totalTurns += 1;
		
		return (totalTurns == 0 ? -1 : totalTurns);
	}
}

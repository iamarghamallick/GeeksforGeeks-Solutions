/* Structure of a Binary Search Tree node
class Node {
	public int data;
	public Node left;
	public Node right;
	
	public Node(int val) {
		data = val;
		left = right = null;
	}
};
*/

class Solution {
	public ArrayList<Integer> findCommon(Node r1, Node r2) {
		Stack<Node> s1 = new Stack<>();
		Stack<Node> s2 = new Stack<>();
		ArrayList<Integer> ans = new ArrayList<>();
		
		while (true) {
			// Push all left nodes of first BST.
			while (r1 != null) {
				s1.push(r1);
				r1 = r1.left;
			}
			
			// Push all left nodes of second BST.
			while (r2 != null) {
				s2.push(r2);
				r2 = r2.left;
			}
			
			// Stop if either traversal is complete.
			if (s1.isEmpty() || s2.isEmpty()) {
				break;
			}
			
			Node curr1 = s1.peek();
			Node curr2 = s2.peek();
			
			if (curr1.data == curr2.data) {
				// Common node found.
				ans.add(curr1.data);
				
				s1.pop();
				s2.pop();
				
				r1 = curr1.right;
				r2 = curr2.right;
				
			} else if (curr1.data < curr2.data) {
				// Advance in first BST.
				s1.pop();
				r1 = curr1.right;
				r2 = null;
				
			} else {
				// Advance in second BST.
				s2.pop();
				r2 = curr2.right;
				r1 = null;
			}
		}
		
		return ans;
	}
	
	private Node insert(Node root, int key) {
		if (root == null) {
			return new Node(key);
		}
		
		if (key < root.data) {
			root.left = insert(root.left, key);
		} else {
			root.right = insert(root.right, key);
		}
		
		return root;
	}
}

// class Solution {
// 	public ArrayList<Integer> findCommon(Node r1, Node r2) {
// 		ArrayList<Integer> arr1 = new ArrayList<>();
// 		ArrayList<Integer> arr2 = new ArrayList<>();
// 		ArrayList<Integer> ans = new ArrayList<>();

// 		inorder(r1, arr1);
// 		inorder(r2, arr2);

// 		for (int i = 0, j = 0; i<arr1.size() && j<arr2.size();) {
// 			if (arr1.get(i) == arr2.get(j)) {
// 				ans.add(arr1.get(i));
// 				i++; j++;
// 			} else if (arr1.get(i) < arr2.get(j)) {
// 				i++;
// 			} else {
// 				j++;
// 			}
// 		}

// 		return ans;
// 	}

// 	private void inorder(Node root, ArrayList<Integer> arr) {
// 		if (root == null) {
// 			return;
// 		}

// 		inorder(root.left, arr);
// 		arr.add(root.data);
// 		inorder(root.right, arr);
// 	}
// }

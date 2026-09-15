/* Binary Tree Node Structure
class Node {
	int data;
	Node left, right;
	
	public Node(int data) {
		this.data = data;
	}
}
*/

class Pair {
	Node node;
	int level;
	
	public Pair(Node node, int level) {
		this.node = node;
		this.level = level;
	}
}

class Solution {
	
	public int getCount(Node root, int k) {
		int count = 0;
		Queue<Pair> q = new LinkedList<>();
		
		q.offer(new Pair(root, 1));
		
		while (!q.isEmpty()) {
			Pair front = q.poll();
			Node node = front.node;
			int level = front.level;
			
			if (node.left == null && node.right == null) {
				if (level <= k) {
					count++;
					k -= level;
				} else {
					break;
				}
			}
			
			if (node.left != null) {
				q.offer(new Pair(node.left, level + 1));
			}
			
			if (node.right != null) {
				q.offer(new Pair(node.right, level + 1));
			}
		}
		
		return count;
	}
}

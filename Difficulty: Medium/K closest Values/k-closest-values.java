/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    private void inorder(Node root, PriorityQueue<int[]> pq, int target, int k) {
        if (root == null) return;

        inorder(root.left, pq, target, k);

        pq.add(new int[]{Math.abs(root.data - target), root.data});
        if (pq.size()>k) pq.poll();

        inorder(root.right, pq, target, k);
    }

    public ArrayList<Integer> getKClosest(Node root, int target, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> { 
            if (a[0] != b[0]) return b[0] - a[0];
            return b[1] - a[1];
        });

        inorder(root, pq, target, k);

        ArrayList<Integer> res = new ArrayList<>();
        while (!pq.isEmpty())
            res.add(pq.poll()[1]);

        return res;
    }
}
/*
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
    public int nodeSum(Node root, int l, int r) {
        if(root == null) return 0;
        if(l <= root.data && root.data <= r) {
            return root.data + nodeSum(root.left, l, r)
                             + nodeSum(root.right, l, r);
        } else {
            return nodeSum(root.left, l, r)
                 + nodeSum(root.right, l, r);
        }
    }
}

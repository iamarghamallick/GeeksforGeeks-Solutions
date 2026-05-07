/*
Definition for Node
class Node {
    int data;
    Node left;
    Node right;

    Node(int x) {
        data = x;
        left = right = null;
    }
}
*/
class Solution {
    public boolean isSubTree(Node root1, Node root2) {
        if (root2 == null) return true;
        if (root1 == null) return false;
    
        if (isSame(root1, root2)) return true;
    
        return isSubTree(root1.left, root2) || isSubTree(root1.right, root2);
    }
    
    private boolean isSame(Node a, Node b) {
        if (a == null && b == null) return true;
        if (a == null || b == null) return false;
    
        if (a.data != b.data) return false;
    
        return isSame(a.left, b.left) && isSame(a.right, b.right);
    }
}
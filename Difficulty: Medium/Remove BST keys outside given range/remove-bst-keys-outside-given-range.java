/*
class Node {
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
}
*/

class Solution {
    Node removekeys(Node root, int l, int r) {
        if(root == null)
            return null;
        
        if(l <= root.data && root.data <= r) {
            root.left = removekeys(root.left, l, r);
            root.right = removekeys(root.right, l, r);
            return root;
        } else if(root.data > r) {
            return removekeys(root.left, l, r);
        } else {
            return removekeys(root.right, l, r);
        }
    }
}
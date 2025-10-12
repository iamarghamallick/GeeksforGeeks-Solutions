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
    int ans;
    
    public int distCandy(Node root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    
    private int dfs(Node root) {
        if(root == null) return 0;
        int l = dfs(root.left);
        int r = dfs(root.right);
        ans += Math.abs(l) + Math.abs(r);
        return root.data + l + r - 1;
    }
}
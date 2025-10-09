/*
class Node {
    int data;
    Node left, right;
    Node(int val){
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    public ArrayList<Integer> postOrder(Node root) {
        ArrayList<Integer> ans = new ArrayList<>();
        traversal(root, ans);
        return ans;
    }
    
    private void traversal(Node root, ArrayList<Integer> ans) {
        if(root == null) return;
        traversal(root.left, ans);
        traversal(root.right, ans);
        ans.add(root.data);
    }
}
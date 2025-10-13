/*
class Node {
    int data;
    Node left, right;

    Node(int data)
    {
        this.data = data;
        this.left = null;
        this.right = null;
    }
}
*/

class Solution {
    public int getMaxSum(Node root) {
        HashMap<Node, Integer> dp = new HashMap<>();
        return solve(root, dp);
    }
    
    private int solve(Node root, HashMap<Node, Integer> dp) {
        if(root == null) return 0;
        if(dp.containsKey(root)) return dp.get(root);
        
        int include = root.data;
        if(root.left != null) 
            include += solve(root.left.left, dp) + solve(root.left.right, dp);
        if(root.right != null)
            include += solve(root.right.left, dp) + solve(root.right.right, dp);
        
        int exclude = solve(root.left, dp) + solve(root.right, dp);
        
        dp.put(root, Math.max(include, exclude));
        return dp.get(root);
    }
}
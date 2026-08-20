/* Structure of binary tree node
class Node
{
    int data;
    Node left, right;

    Node(int item)
    {
        data = item;
        left = right = null;
    }
}
*/

class Solution {
    
    int ans;
    
    int maxDiff(Node root) {
        ans = Integer.MIN_VALUE;
        solve(root);
        return ans;
    }
    
    int solve(Node root) {
        if(root == null) {
            return Integer.MAX_VALUE;
        }
        
        if(root.left == null && root.right == null) {
            return root.data;
        }
        
        int minVal = Math.min(solve(root.left), solve(root.right));
        
        ans = Math.max(ans, root.data - minVal);
        
        return Math.min(root.data, minVal);
    }
}
/*
class Node {
    int data;
    Node left, right;

    public Node(int d)
    {
        data = d;
        left = right = null;
    }
}
*/

class Solution {
    public int kthSmallest(Node root, int k) {
        List<Integer> arr = new ArrayList<>();
        
        solve(root, k, arr);
        
        if(arr.size() >= k)
            return arr.get(k-1);
        
        return -1;
    }
    
    private void solve(Node root, int k, List<Integer> arr) {
        if(root == null || arr.size() >= k)
            return;
        
        solve(root.left, k, arr);
        arr.add(root.data);
        solve(root.right, k, arr);
    }
}
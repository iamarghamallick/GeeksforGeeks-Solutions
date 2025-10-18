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
    public int findMedian(Node root) {
        int n = countNodes(root);
        
        if(n%2 == 0) n = n/2;
        else n = (n+1)/2;
        
        int[] arr = new int[2]; // [count, ans]
        arr[0] = n;
        findMedianValue(root, arr);
        
        return arr[1];
    }
    
    private int countNodes(Node root) {
        if(root == null) return 0;
        int l = countNodes(root.left);
        int r = countNodes(root.right);
        return 1 + l + r;
    }
    
    private void findMedianValue(Node root, int[] arr) {
        if(root == null) return;
        
        findMedianValue(root.left, arr);
        
        arr[0] -= 1;
        if(arr[0] == 0) {
            arr[1] = root.data;
            return;
        }
        
        findMedianValue(root.right, arr);
    }
}
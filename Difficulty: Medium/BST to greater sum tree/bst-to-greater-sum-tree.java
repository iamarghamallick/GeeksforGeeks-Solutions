/*
class Node{
    int data;
    Node left;
    Node right;
    Node(int data){
        this.data = data;
        left=null;
        right=null;
    }
} */

class Solution {
    public static void transformTree(Node root) {
        List<Integer> arr = new ArrayList<>();
        Map<Integer, Integer> map = new HashMap<>();
        inorder(root, arr);
        int sum = 0;
        for(int i=arr.size()-1; i>=0; i--) {
            map.put(arr.get(i), sum);
            sum += arr.get(i);
        }
        transform(root, map);
    }
    
    private static void inorder(Node root, List<Integer> arr) {
        if(root == null) return;
        inorder(root.left, arr);
        arr.add(root.data);
        inorder(root.right, arr);
    }
    
    private static void transform(Node root, Map<Integer, Integer> map) {
        if(root == null) return;
        transform(root.left, map);
        root.data = map.get(root.data);
        transform(root.right, map);
    }
}
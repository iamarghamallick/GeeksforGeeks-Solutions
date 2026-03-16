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
    private int count = 0;
    
    public int countAllPaths(Node root, int k) {
        HashMap<Integer, Integer> map = new HashMap<>();
        map.put(0, 1);
        totalPaths(root, map, k, 0);
        return count;
    }
    
    public void totalPaths(Node root, HashMap<Integer, Integer> map, int k, int sum) {
        if(root == null) {
            return;
        }
        
        sum += root.data;
        if(map.containsKey(sum-k)) {
            count += map.get(sum-k);
        }
        map.put(sum, map.getOrDefault(sum, 0)+1);
        totalPaths(root.left, map, k, sum);
        totalPaths(root.right, map, k, sum);
        map.put(sum, map.get(sum)-1);
    }
}
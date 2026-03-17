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
    HashMap<Integer, Pair> map = new HashMap<>();
    
    public void dfs(Node node, Node parent) {
        if(node == null) return;
        
        Node left = node.left == null ? null : node.left;
        Node right = node.right == null ? null : node.right;
        
        map.put(node.data, new Pair(node.data, left, right, parent));
        
        dfs(node.left, node);
        dfs(node.right, node);
        
    }
    
    public int minTime(Node root, int target) {
        map = new HashMap<>();
        dfs(root, null);

        Queue<Pair> q = new LinkedList<>();

        q.add(new Pair(target, map.get(target).left, map.get(target).right, map.get(target).parent));

        int time = 0;

        HashSet<Integer> visited = new HashSet<>();
        visited.add(target);

        while (!q.isEmpty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Pair curr = q.remove();
                int data = curr.node;
                Node left = map.get(data).left, right = map.get(data).right, parent = map.get(data).parent;

                if (left != null && !visited.contains(left.data)) {
                    visited.add(left.data);
                    q.add(map.get(left.data));
                }

                if (right != null && !visited.contains(right.data)) {
                    visited.add(right.data);
                    q.add(map.get(right.data));
                }

                if (parent != null && !visited.contains(parent.data)) {
                    visited.add(parent.data);
                    q.add(map.get(parent.data));
                }
            }

            time++;

        }

        return time - 1;
        
    }
}

class Pair {
    int node;
    Node left, right, parent;
    public Pair(int n, Node l, Node r, Node p) {
        this.node = n;
        this.left = l;
        this.right = r;
        this.parent = p;
    }
}
/*
class Node {
    int data;
    Node next;
    Node bottom;

    Node(int x) {
        data = x;
        next = null;
        bottom = null;
    }
}
*/
class Solution {
    public Node flatten(Node root) {
        List<Node> list = new ArrayList<>();
        PriorityQueue<Node> pq = new PriorityQueue<>((n1, n2) -> n1.data - n2.data);
        while(root != null) {
            Node temp = root.next;
            root.next = null;
            pq.add(root);
            root = temp;
        }
        root = new Node(-1);
        Node ans = root;
        while(!pq.isEmpty()) {
            Node cur = pq.poll();
            Node next = cur.bottom;
            cur.bottom = null;
            root.bottom = cur;
            root = root.bottom;
            if(next != null) pq.add(next);
        }
        root.bottom = null;
        return ans.bottom;
    }
}
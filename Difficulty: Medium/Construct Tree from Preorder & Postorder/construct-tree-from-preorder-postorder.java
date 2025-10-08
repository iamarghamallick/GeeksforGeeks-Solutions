/*
class Node {
    int data;
    Node left, right;

    Node(int val) {
        data = val;
        left = right = null;
    }
}
*/

class Solution {
    int preIndex = 0;
    Map<Integer, Integer> postMap = new HashMap<>();

    public Node constructTree(int[] pre, int[] post) {
        for (int i = 0; i < post.length; i++) {
            postMap.put(post[i], i);
        }
        return build(pre, post, 0, post.length - 1);
    }

    private Node build(int[] pre, int[] post, int start, int end) {
        if (preIndex >= pre.length || start > end)
            return null;

        Node root = new Node(pre[preIndex++]);
        if (start == end || preIndex >= pre.length)
            return root;

        int leftIndex = postMap.get(pre[preIndex]);

        root.left = build(pre, post, start, leftIndex);
        root.right = build(pre, post, leftIndex + 1, end - 1);

        return root;
    }
}
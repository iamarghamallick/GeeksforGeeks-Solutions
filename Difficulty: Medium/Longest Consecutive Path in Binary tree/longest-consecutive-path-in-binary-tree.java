/* Structure of Binary Tree Node
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
}*/

class Pair {
    Node node;
    int length;

    Pair(Node node, int length) {
        this.node = node;
        this.length = length;
    }
}

class Solution {
    public int longestConsecutive(Node root) {
        if (root == null)
            return -1;

        int result = 1;
        Stack<Pair> st = new Stack<>();
        st.push(new Pair(root, 1));

        while (!st.isEmpty()) {
            Pair curr = st.pop();
            Node node = curr.node;
            int len = curr.length;

            result = Math.max(result, len);

            if (node.left != null) {
                if (node.left.data == node.data + 1)
                    st.push(new Pair(node.left, len + 1));
                else
                    st.push(new Pair(node.left, 1));
            }

            if (node.right != null) {
                if (node.right.data == node.data + 1)
                    st.push(new Pair(node.right, len + 1));
                else
                    st.push(new Pair(node.right, 1));
            }
        }

        return result == 1 ? -1 : result;
    }
}
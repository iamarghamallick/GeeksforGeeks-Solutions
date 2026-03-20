class Solution {
    public ArrayList<Node> findPreSuc(Node root, int key) {
        ArrayList<Node> ans = new ArrayList<>();
        Node pre = null;
        Node suc = null;
        Node cur = root;
        
        while(cur != null) {
            if(cur.data == key) {
                // predecessor
                if(cur.left != null) {
                    Node temp = cur.left;
                    while(temp.right != null) {
                        temp = temp.right;
                    }
                    pre = temp;
                }
                
                // successor
                if(cur.right != null) {
                    Node temp = cur.right;
                    while(temp.left != null) {
                        temp = temp.left;
                    }
                    suc = temp;
                }
                break;
            } 
            else if(cur.data > key) {
                suc = cur;
                cur = cur.left;
            } 
            else {
                pre = cur;
                cur = cur.right;
            }
        }
        
        ans.add(pre);
        ans.add(suc);
        
        return ans;
    }
}
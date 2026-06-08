/* Structure of linked list node
class Node {

    int data;
    Node next;

    Node(int d) {
        data = d;
        next = null;
    }
}
*/
class Solution {
    Node reverse(Node head) {
        Node curr = head;
        Node prev = null;
        Node next = null;
        while(curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    
    Node compute(Node head) {
        // 1. reverse the list
        head = reverse(head);
        
        // 2. delete nodes 
        // which have a node with greater value 
        // on the left side
        Node curr = head;
        Node maxNode = head;
        while(curr != null && curr.next != null) {
            if(curr.next.data < maxNode.data) {
                curr.next = curr.next.next;
            } else {
                curr = curr.next;
                maxNode = curr;
            }
        }
        
        // 3. againg reverse the list
        head = reverse(head);
        
        return head;
    }
}
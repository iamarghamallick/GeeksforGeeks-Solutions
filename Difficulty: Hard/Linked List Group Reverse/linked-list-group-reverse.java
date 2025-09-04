/*
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}
*/

class Solution {
    private Node findKthNode(Node head, int k) {
        Node temp = head;
        
        while(temp.next != null) {
            --k;
            if(k == 0) break;
            temp = temp.next;
        }
        
        return temp;
    }
    
    private Node reverseLL(Node head) {
        Node curr = head, prevNode = null, nextNode = null;
        
        while(curr != null) {
            nextNode = curr.next;
            curr.next = prevNode;
            prevNode = curr;
            curr = nextNode;
        }
        
        return prevNode;
    }
    
    public Node reverseKGroup(Node head, int k) {
        Node temp = head, nextNode = null, prevNode = null;
        
        while(temp != null) {
            Node kthNode = findKthNode(temp, k);
            
            nextNode = kthNode.next;
            kthNode.next = null;
            Node newHead = reverseLL(temp);
            
            if(temp == head) {
                head = kthNode;
            } else {
                prevNode.next = kthNode;
            }
            
            prevNode = temp;
            temp = nextNode;
        }
        
        return head;
    }
}
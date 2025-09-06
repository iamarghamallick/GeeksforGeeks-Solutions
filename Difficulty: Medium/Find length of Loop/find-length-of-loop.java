/*
class Node {
    int data;
    Node next;

    Node(int x) {
        data = x;
        next = null;
    }
}
*/

class Solution {
    public int lengthOfLoop(Node head) {
        Node slow = head, fast = head.next;
        while(slow != null && fast != null && fast.next != null) {
            if(slow == fast) { // loop is detected
                int count = 1;
                slow = slow.next;
                while(slow != fast) {
                    count++;
                    slow = slow.next;
                }
                return count;
            }
            
            slow = slow.next;
            fast = fast.next.next;
        }
        return 0;
    }
}
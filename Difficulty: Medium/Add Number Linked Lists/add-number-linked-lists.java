/*
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
    public Node addTwoLists(Node head1, Node head2) {
        Stack<Integer> s1 = new Stack<>();
        Stack<Integer> s2 = new Stack<>();
        
        while(head1!=null){
            s1.push(head1.data);
            head1 = head1.next;
        }
        while(head2!=null){
            s2.push(head2.data);
            head2 = head2.next;
        }
        
        int carry = 0;
        Node result = null;
        
        while(!s1.isEmpty() || !s2.isEmpty() || carry != 0){
            int sum = carry ;
            
            if(!s1.isEmpty()){
                sum += s1.pop();
            }
            if(!s2.isEmpty()){
                sum += s2.pop();
            }
            carry = sum/10;
            int digit = sum%10;
            
            Node newNode = new Node(digit);
            newNode.next = result;
            result = newNode;
        }
        while(result!=null && result.data == 0 && result.next!=null){
            result = result.next;
        }
        
        return result;
    }
}
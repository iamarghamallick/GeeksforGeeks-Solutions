/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution {
  public:
    Node* segregate(Node* head) {
        int z = 0, o = 0, t = 0;
        Node* temp = head;
        while(temp) {
            if(temp->data == 0) z++;
            else if(temp->data == 1) o++;
            else t++;
            temp = temp->next;
        }
        
        temp = head;
        while(z) {
            temp->data = 0;
            z--;
            temp = temp->next;
        }
        while(o) {
            temp->data = 1;
            o--;
            temp = temp->next;
        }
        while(t) {
            temp->data = 2;
            t--;
            temp = temp->next;
        }
        
        return head;
    }
};
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution {
  public:
    Node* merge(Node* leftHead, Node* rightHead) {
        if(!leftHead) return rightHead;
        if(!rightHead) return leftHead;
        
        Node* head = NULL;
        Node* temp = NULL;
        
        if(leftHead->data < rightHead->data) {
            head = leftHead;
            leftHead = leftHead->next;
        } else {
            head = rightHead;
            rightHead = rightHead->next;
        }
        
        temp = head;
        
        while(leftHead && rightHead) {
            if(leftHead->data < rightHead->data) {
                temp->next = leftHead;
                temp = temp->next;
                leftHead = leftHead->next;
            } else {
                temp->next = rightHead;
                temp = temp->next;
                rightHead = rightHead->next;
            }
        }
        
        while(leftHead) {
            temp->next = leftHead;
            temp = temp->next;
            leftHead = leftHead->next;
        }
        
        while(rightHead) {
            temp->next = rightHead;
            temp = temp->next;
            rightHead = rightHead->next;
        }
        
        return head;
    }
    
    Node* getMid(Node* head) {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow;
    }
  
    Node* mergeSort(Node* head) {
        if(!head || !head->next) return head;
        
        Node* mid = getMid(head);
        Node* rightHead = mid->next;
        mid->next = NULL;
        
        Node* left = mergeSort(head);
        Node* right = mergeSort(rightHead);
        
        return merge(left, right);
    }
};
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
    Node* mergeTwo(Node* head1, Node* head2) {
  
        // Create a dummy node to simplify 
        // the merging process
        Node* dummy = new Node(-1);
        Node* curr = dummy;
    
        // Iterate through both linked lists
        while (head1 != nullptr && head2 != nullptr) {
          
            // Add the smaller node to the merged list
            if (head1->data <= head2->data) {
                curr->next = head1;
                head1 = head1->next;
            } else {
                curr->next = head2;
                head2 = head2->next;
            }
            curr = curr->next;
        }
    
        // If any list is left, append it to
        // the merged list
        if (head1 != nullptr) {
            curr->next = head1;
        } else {
            curr->next = head2;
        }
    
        // Return the merged list starting
        // from the next of dummy node
        return dummy->next;
    }
  
    Node* mergeListsRecur(int i, int j, vector<Node*> &arr) {
    
        // If single list is left
        if (i == j) return arr[i];
        
        // Find the middle of lists
        int mid = i + (j-i)/2;
        
        // Merge lists from i to mid 
        Node* head1 = mergeListsRecur(i, mid, arr);
        
        // Merge lists from mid+1 to j 
        Node* head2 = mergeListsRecur(mid+1, j, arr);
        
        // Merge the above 2 lists 
        Node* head = mergeTwo(head1, head2);
        
        return head;
    }

    Node* mergeKLists(vector<Node*>& arr) {
        // Your code here
        if (arr.size()==0) return nullptr;
  
        return mergeListsRecur(0, arr.size()-1, arr);
    }
};
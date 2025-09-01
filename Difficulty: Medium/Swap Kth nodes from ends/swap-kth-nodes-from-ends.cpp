/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    Node* swapKth(Node* head, int k) {
        if (!head) return head;

        // Step 1: Count length of the list
        int n = 0;
        Node* temp = head;
        while (temp) {
            n++;
            temp = temp->next;
        }

        if (k > n) return head;              // invalid k
        if (2 * k - 1 == n) return head;     // kth from start == kth from end (same node)

        // Step 2: Find kth node from start and end
        Node* prevLeft = NULL, *left = head;
        for (int i = 1; i < k; i++) {
            prevLeft = left;
            left = left->next;
        }

        Node* prevRight = NULL, *right = head;
        for (int i = 1; i < n - k + 1; i++) {
            prevRight = right;
            right = right->next;
        }

        // Step 3: Fix previous pointers
        if (prevLeft) prevLeft->next = right;
        if (prevRight) prevRight->next = left;

        // Step 4: Swap next pointers
        Node* tmp = left->next;
        left->next = right->next;
        right->next = tmp;

        // Step 5: Update head if needed
        if (k == 1) head = right;
        else if (k == n) head = left;

        return head;
    }
};
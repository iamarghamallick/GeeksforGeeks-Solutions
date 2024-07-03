//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
// User function Template for C++

/* Linked List node structure

struct Node {
    int data;
    struct Node *next;
};

*/

class Solution {
  public:
    Node* removeAllDuplicates(struct Node* head) {
        struct Node* ans = nullptr, *temp = nullptr, *curr = head->next;
        int count = 1, val = head->data;
        while(curr) {
            if(curr->data == val)
                count++;
            else {
                if(count == 1)  insert(ans, temp, val);
                count = 1;
                val = curr->data;
            }
            curr = curr->next;
        }
        if(count == 1)  insert(ans, temp, val);
        return ans;
    }
    
  private:
    void insert(struct Node* &ans, struct Node* &temp, int val) {
        if(!ans) {
            ans = new Node(val);
            temp = ans;
        } else {
            temp->next = new Node(val);
            temp = temp->next;
        }
    }
};

//{ Driver Code Starts.
/* Function to print linked list */
void printList(struct Node *head) {
    struct Node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Driver program to test above functions
int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;

        cin >> N;

        Node *head = NULL;
        Node *temp = head;

        for (int i = 0; i < N; i++) {
            int data;
            cin >> data;
            if (head == NULL)
                head = temp = new Node(data);
            else {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }

        Solution ob;
        head = ob.removeAllDuplicates(head);
        printList(head);

        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends
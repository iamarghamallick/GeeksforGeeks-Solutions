//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

/* Link list Node */
class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

void freeList(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        delete temp;
    }
}


// } Driver Code Ends

/*  Node is defined as
  struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};*/
class Solution {
  public:
    Node* segregate(Node* head) {
        int zero = 0, one = 0, two = 0;
        for(Node* curr = head; curr != NULL; curr = curr->next) {
            if(curr->data == 0) zero++;
            else if(curr->data == 1) one++;
            else two++;
        }
        
        Node* ans = NULL, *temp = NULL;
        
        while(zero--) {
            if(!ans) {
                ans = new Node(0);
                temp = ans;
            } else {
                temp->next = new Node(0);
                temp = temp->next;
            }
        }
        
        while(one--) {
            if(!ans) {
                ans = new Node(1);
                temp = ans;
            } else {
                temp->next = new Node(1);
                temp = temp->next;
            }
        }
        
        while(two--) {
            if(!ans) {
                ans = new Node(2);
                temp = ans;
            } else {
                temp->next = new Node(2);
                temp = temp->next;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

// Driver program to test above functions
int main() {
    int t, k;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t

    while (t--) {
        string input;
        getline(cin, input); // Read the entire line for the array elements

        stringstream ss(input);
        Node *head = nullptr, *tail = nullptr;
        int x;

        if (ss >> x) {
            head = new Node(x);
            tail = head;

            while (ss >> x) {
                tail->next = new Node(x);
                tail = tail->next;
            }

            // Link the last node to the head if k is 1 to make it circular
            if (k == 1) {
                tail->next = head;
            }
        }

        Solution ob;
        Node* newHead = ob.segregate(head);
        printList(newHead);
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends
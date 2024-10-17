//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*
struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }

};
*/

class Solution {
  public:
    void addNode(struct Node* &head, struct Node* &temp, int data) {
        if(!head) {
            head = new Node(data);
            temp = head;
        } else {
            temp->next = new Node(data);;
            temp = temp->next;
        }
    }
    
    // Function to split a linked list into two lists alternately
    vector<Node*> alternatingSplitList(struct Node* head) {
        struct Node* head1 = nullptr, *head2 = nullptr;
        struct Node* temp1 = nullptr, *temp2 = nullptr;
        int index = 1;
        while(head) {
            if(index % 2 == 0)
                addNode(head2, temp2, head->data);
            else 
                addNode(head1, temp1, head->data);
            
            head = head->next;
            index++;
        }
        
        return { head1, head2 };
    }
};


//{ Driver Code Starts.

void printList(struct Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        while (ss >> number) {
            arr.push_back(number);
        }

        struct Node* head = new Node(arr[0]);
        struct Node* tail = head;

        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }

        Solution ob;
        vector<Node*> result = ob.alternatingSplitList(head);
        printList(result[0]);
        printList(result[1]);
    }

    return 0;
}

// } Driver Code Ends
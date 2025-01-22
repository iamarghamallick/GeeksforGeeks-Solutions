//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    Node* reverse(Node* head){
        if(!head || !head->next) return head;
        
        Node* anshead=reverse(head->next);
        Node* front=head->next;
        head->next=NULL;
        front->next=head;
        return anshead;
    }
  
    Node* addTwoLists(Node* num1, Node* num2) {
        // code here
        int carry=0;
        Node* temp1=reverse(num1),*temp2=reverse(num2);
        
        Node* ans=new Node(-1);
        Node* dummy=ans;
        
        while(temp1 || temp2){
            int sum=carry;
            if(temp1){
                sum+=temp1->data;
                temp1=temp1->next;
            } 
            if(temp2){
                sum+=temp2->data;
                temp2=temp2->next;
            }
            
            dummy->next=new Node(sum%10);
            carry=sum/10;
            dummy=dummy->next;
        }
        
        if(carry){
            dummy->next=new Node(carry);
            dummy=dummy->next;
        }
        
        ans=ans->next;
        Node* updatedans=reverse(ans);
        while(updatedans && updatedans->data==0){
            updatedans=updatedans->next;
        }
        
        return updatedans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
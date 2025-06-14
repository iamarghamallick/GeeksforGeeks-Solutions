/*
class Node {
public:
    int data;
    Node *left, *right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};
*/
class Solution {
  public:
    void preOrder(Node* root, vector<int> &arr) {
        if(!root) {
            arr.push_back(-1);
            return;
        }
        
        arr.push_back(root->data);
        
        preOrder(root->left, arr);
        preOrder(root->right, arr);
    }
    
    void revOrder(Node* root, vector<int> &arr) {
        if(!root) {
            arr.push_back(-1);
            return;
        }
        
        arr.push_back(root->data);
        
        revOrder(root->right, arr);
        revOrder(root->left, arr);
    }
    
    bool isSymmetric(Node* root) {
        vector<int> pre, rev;
        
        preOrder(root, pre);
        revOrder(root, rev);
        
        for(int i=0; i<pre.size(); i++) {
            if(pre[i] != rev[i])
                return false;
        }
        
        return true;
    }
};
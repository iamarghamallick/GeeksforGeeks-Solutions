/*
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
}; */

class Solution {
  public:
    void solve(Node* root, int k, int& ans){
        if(!root) return ;
        if((k-root->data) >= 0) {
            ans = max(ans, root->data);
            solve(root->right,k,ans);
        } else {
            solve(root->left,k,ans);
        }
    }
    
    int findMaxFork(Node* root, int k) {
        int ans = -1;
        solve(root,k,ans);
        return ans;
    }
};
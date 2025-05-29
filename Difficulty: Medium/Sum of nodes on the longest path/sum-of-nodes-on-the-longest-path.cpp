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
    void solve(Node*root,int l,int sum,int&h,int& ans){
        if(!root) return;
        sum += root->data;
        if(!root->left && !root->right){
            if(l>h)
                ans = sum;
            else if(l==h)
                ans = max(sum,ans);
        }
        h = max(h,l);
        solve(root->left,l+1,sum,h,ans);
        solve(root->right,l+1,sum,h,ans);
    }
    
    int sumOfLongRootToLeafPath(Node *root) {
        int ans = 0;
        int h = -1;
        solve(root,0,0,h,ans);
        return ans;
    }


};
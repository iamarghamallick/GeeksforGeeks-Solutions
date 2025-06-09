/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
    bool helper(Node *node, int min, int max) {
        if(!node)
            return false;
        if(node->data == min && node->data == max)
            return true;
        return helper(node->left, min, node->data-1) || helper(node->right, node->data+1, max);
    }
    
    bool isDeadEnd(Node *root) {
        return helper(root, 1, 10001);
    }
};

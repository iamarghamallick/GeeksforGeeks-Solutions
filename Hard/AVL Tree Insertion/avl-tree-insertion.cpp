//{ Driver Code Starts
//

#include <bits/stdc++.h>
#define MAXN 2000
using namespace std;

struct Node
{
    int data, height;
    Node *left, *right;
    
    Node(int x)
    {
        data=x;
        left=right=NULL;
        height=1;
    }
};

bool isBST(Node *n, int lower, int upper)
{
	if(!n) return 1;
	if( n->data <= lower || n->data >= upper ) return 0;
	return isBST(n->left, lower, n->data) && isBST(n->right, n->data, upper) ;
}

pair<int,bool> isBalanced(Node* n)
{
	if(!n) return pair<int,bool> (0,1);

	pair<int,bool> l = isBalanced(n->left);
	pair<int,bool> r = isBalanced(n->right);

	if( abs(l.first - r.first) > 1 ) return pair<int,bool> (0,0);

	return pair<int,bool> ( 1 + max(l.first , r.first) , l.second && r.second );
}

bool isBalancedBST(Node* root)
{
	if( !isBST(root, INT_MIN, INT_MAX) )
		cout<< "BST voilated, inorder traversal : ";

	else if ( ! isBalanced(root).second )
		cout<< "Unbalanced BST, inorder traversal : ";

	else return 1;
	return 0;
}

void printInorder(Node* n)
{
	if(!n) return;
	printInorder(n->left);
	cout<< n->data << " ";
	printInorder(n->right);
}


// } Driver Code Ends
/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

unordered_map<Node*, int> height;

class Solution{
  public:
    Node * leftRotate(Node *node) {
        Node * toreturn = node->right;
        
        node->right = toreturn->left;
        toreturn->left = node;
        
        return toreturn;
    }
    
    Node * rightRotate(Node *node) {
        Node * toreturn = node->left;
        
        node->left = toreturn->right;
        toreturn->right = node;
        
        return toreturn;
    }
    
    /*You are required to complete this method */
    Node* insertToAVL(Node* node, int data)
    {
        //Your code here
        if(node == nullptr) {
            Node * nn = new Node(data);
            height[nn] = 1;
            return nn;
        }
        
        if(data < node->data)
            node->left = insertToAVL(node->left, data);
        else 
            node->right = insertToAVL(node->right, data);
            
        auto he = [&](Node *node)->int {
            if(node == nullptr)
                return 0;
            return height[node] = max(height[node->left], height[node->right]) + 1;
        };
        
        int bf = he(node->left) - he(node->right);
        
        if(abs(bf) > 1) {
            if(bf < 0) {
                // right imbalance
                if(data < (node->right)->data) {
                    // right - left imbalance
                    node->right = rightRotate(node->right);
                    node = leftRotate(node);
                } else {
                    // right -right imbalance
                    node = leftRotate(node);
                }
            } else {
                // left imbalance
                if(data < (node->left)->data) {
                    // left - left imbalance
                    node = rightRotate(node);
                } else {
                    // left - right imbalance
                    node->left = leftRotate(node->left);
                    node = rightRotate(node);
                }
            }
            
            he(node);
            he(node->left);
            he(node->right);
        }
        
        return node;
    }
};

//{ Driver Code Starts.

int main()
{
	int ip[MAXN];
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        for(int i=0; i<n; i++)
            cin>> ip[i];
        
        Node* root = NULL;
        Solution obj;
        for(int i=0; i<n; i++)
        {
            root = obj.insertToAVL( root, ip[i] );
            
            if ( ! isBalancedBST(root) )
                break;
        }
        
        printInorder(root);
        cout<< endl;
    }
    return 0;
}
// } Driver Code Ends
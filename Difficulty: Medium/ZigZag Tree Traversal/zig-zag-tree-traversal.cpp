//User function Template for C++
/*Structure of the node of the binary tree is as
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector<int> zigZagTraversal(Node* root) {
    	vector<int> ans;
    	stack<Node*> currLevel, nextLevel;
    	
    	currLevel.push(root);
    	bool LtoR = true;
    	
    	while(!currLevel.empty()) {
    	    Node* temp = currLevel.top();
    	    currLevel.pop();
    	    
    	    if(temp) {
    	        ans.push_back(temp->data);
    	        
    	        if(LtoR) {
    	            if(temp->left) nextLevel.push(temp->left);
    	            if(temp->right) nextLevel.push(temp->right);
    	        } else {
    	            if(temp->right) nextLevel.push(temp->right);
    	            if(temp->left) nextLevel.push(temp->left);
    	        }
    	    }
    	    
    	    if(currLevel.empty()) {
    	        LtoR = !LtoR;
    	        swap(currLevel, nextLevel);
    	    }
    	}
    	
    	return ans;
    }
};

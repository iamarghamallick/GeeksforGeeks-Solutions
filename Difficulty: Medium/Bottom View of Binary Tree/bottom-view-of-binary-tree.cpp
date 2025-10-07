//Function to return a list containing the bottom view of the given tree.

class Solution {
  public:
    vector<int> bottomView(Node *root) {
        vector<int> ans;
        
        if(!root)   return ans;
        
        map<int, int> map;
        queue<pair<int, Node*> > q;
        q.push({0, root});
        
        while(!q.empty()) {
            pair<int, Node*> temp = q.front();
            q.pop();
            
            int x = temp.first;
            Node* node = temp.second;
            
            map[x] = node->data;
            
            if(node->left)
                q.push({x - 1, node->left});
            if(node->right)
                q.push({x + 1, node->right});
        }
        
        for(auto it : map)
            ans.push_back(it.second);
        
        return ans;
    }
};

//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
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
class Solution {
  public:
    void solve(int &maxi, Node* root){
        if(!root)
            return;
        maxi = max(maxi, root->data);
        solve(maxi, root->left);
        solve(maxi, root->right);
    }
    
    void constructGraph(Node* root, vector<int>adj[]) {
        if(!root)
            return;
            
        if(root->left) {
            adj[root->data].push_back(root->left->data);
            adj[root->left->data].push_back(root->data);
        }
        if(root->right) {
            adj[root->data].push_back(root->right->data);
            adj[root->right->data].push_back(root->data);
        }
        constructGraph(root->left, adj);
        constructGraph(root->right, adj);
    }
    
    int minTime(Node* root, int target) {
        int maxi = -1;
        solve(maxi, root);
        vector<int> adj[maxi+1];
        constructGraph(root,adj);
        queue<pair<int,int>> q;
        vector<bool> visit(maxi+1, false);
        q.push({ 0, target });
        visit[target] = true;
        int ans = 0;
        
        while(!q.empty()) {
            int dist = q.front().first;
            int u = q.front().second;
            q.pop();
            ans = max(ans,dist);
            
            for(auto v:adj[u]) {
                if(!visit[v]) {
                    visit[v] = true;
                    q.push({dist+1,v});
                }
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends
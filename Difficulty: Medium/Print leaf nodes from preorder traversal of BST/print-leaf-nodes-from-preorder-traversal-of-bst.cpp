class Solution {
  public:
    void helper(int s , int e , vector<int> &preorder , vector<int> &inorder,vector<int> &ans , int &index){
        
        if(s > e  || index >= preorder.size()) return;
        if(s == e){
            ans.push_back(inorder[s]);
            index++;
            return;
        }
        
        int elem = preorder[index];
        index++;
        int temp = -1;
        for(int i=s ; i <= e ; i++){
            if(elem == inorder[i]){
                temp = i;
                break;
            }
        }
        
        helper(s,temp-1,preorder,inorder,ans,index);
        helper(temp+1,e,preorder,inorder,ans,index);
        
        
        
    }
    
    vector<int> leafNodes(vector<int>& preorder) {
       vector<int> inorder = preorder;
       sort(inorder.begin(),inorder.end());
       int index = 0;
       vector<int> ans;
       helper(0,preorder.size()-1,preorder,inorder,ans,index);
       return ans;
        
    }
};
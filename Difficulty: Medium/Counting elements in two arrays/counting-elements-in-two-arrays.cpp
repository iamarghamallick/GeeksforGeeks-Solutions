class Solution {
  public:
    int upperIndex(vector<int>& b, int z){
        int l = 0, r = b.size()-1;
        int ans = r+1;
        
        while(l<=r){
            int m = l+(r-l)/2;
            if(b[m] <= z){
                l = m+1;
            }
            else{
                ans = m;
                r = m-1;
            }
        }
        return ans;
    }
  
    vector<int> countLessEq(vector<int>& a, vector<int>& b) {
        sort(b.begin(), b.end());
        vector<int> ans;
        
        for(auto z : a){
            int t = upperIndex(b, z);
            ans.push_back(t);
        }
        
        return ans;
    }
};
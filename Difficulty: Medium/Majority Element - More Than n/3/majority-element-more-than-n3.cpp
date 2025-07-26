class Solution {
  public:
    vector<int> findMajority(vector<int>& arr) {
        map<int,int>mp;
        vector<int>ans;
        int n=arr.size()/3;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        for(auto it : mp){
            if(it.second>n){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};
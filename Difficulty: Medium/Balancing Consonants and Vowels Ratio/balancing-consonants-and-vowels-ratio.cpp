class Solution {
  public:
    int countBalanced(vector<string>& arr) {
        vector<int>vp;
        int count=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i].size();
            int v=0;
            int c=0;
            for(int j=0;j<arr[i].size();j++)
            {
                if(arr[i][j]=='a' || arr[i][j]=='e' || arr[i][j]=='i' || arr[i][j]=='o' ||arr[i][j]=='u')
                {
                    ++v;
                }
                else
                {
                    ++c;
                }
                
            }
            vp.push_back(v-c);
        }
        for(int i=0;i<vp.size();i++)
        {
           sum+=vp[i];
           count+=mp[sum];
           ++mp[sum];
        }
        return count;
    }
};
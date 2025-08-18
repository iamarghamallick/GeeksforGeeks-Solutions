class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        
        priority_queue<int> pq;
        
        for(auto& it: citations)pq.push(it); 
        int cnt=0;
        
        int ans=-1e9;
        int maxi=1e9;
        while(!pq.empty())
        {
            int a=pq.top();
            pq.pop();
            cnt++;
            maxi=min(maxi,a);
            if(maxi>=cnt)
            {
                ans=max(ans,cnt);
            }
        }
        if(ans==-1e9)return 0;
        return ans;
    }
};
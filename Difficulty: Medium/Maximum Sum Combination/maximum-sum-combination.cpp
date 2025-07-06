class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        int n = a.size();
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        
        priority_queue<pair<int, pair<int, int>>> pq;
        set<pair<int, int>> set;
        
        pq.push({a.back() + b.back(), {n-1, n-1}});
        set.insert({n-1, n-1});
        
        vector<int> ans;
        
        while(k--) {
            auto top = pq.top();
            pq.pop();
            
            int sum = top.first;
            int i = top.second.first;
            int j = top.second.second;
            
            ans.push_back(sum);
            
            if(set.find({i, j-1}) == set.end()) {
                pq.push({a[i] + b[j-1], {i, j-1}});
                set.insert({i, j-1});
            }
            
            if(set.find({i-1, j}) == set.end()) {
                pq.push({a[i-1] + b[j], {i-1, j}});
                set.insert({i-1, j});
            }
        }
        
        return ans;
    }
};
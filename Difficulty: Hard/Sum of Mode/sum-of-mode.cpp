class Solution {
  public:
    struct cmp {
        bool operator()(const pair<int, int> &a , const pair<int, int> &b) {
            if(a.first == b.first)
                return a.second < b.second;
            
            return a.first > b.first;
        }
    };
    
    int sumOfModes(vector<int>& arr, int k) {
        int n = arr.size();
        
        set<pair<int, int>, cmp> s;
        map<int, int> mp;
        for(int i=0; i<k; i++) {
            s.erase({mp[arr[i]], arr[i]});
            mp[arr[i]]++;
            s.insert({mp[arr[i]], arr[i]});
        }
        
        vector<int> v;
        
        auto it = s.begin();
        int ans = 0;
        
        ans += it->second;
        
        for(int i=k; i<n; i++) {
            s.erase({mp[arr[i-k]], arr[i-k]});
            mp[arr[i-k]]--;
            s.insert({mp[arr[i-k]], arr[i-k]});
            
            s.erase({mp[arr[i]], arr[i]});
            mp[arr[i]]++;
            s.insert({mp[arr[i]], arr[i]});
            
            auto it = s.begin();
            ans += it->second;
        }
        
        return ans;
    }
};
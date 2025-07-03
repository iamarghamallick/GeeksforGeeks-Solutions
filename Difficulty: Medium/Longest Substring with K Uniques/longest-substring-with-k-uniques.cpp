class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        int n = s.size();
        unordered_map<int, int> map;
        int start = 0, maxLen = -1;
        
        for(int end=0; end<n; end++) {
            map[s[end]]++;
            
            while(start < n && map.size() > k) {
                map[s[start]]--;
                if(map[s[start]] == 0)
                    map.erase(s[start]);
                start++;
            }
            
            if(map.size() == k)
                maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};
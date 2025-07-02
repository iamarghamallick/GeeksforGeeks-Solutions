class Solution {
  public:
    int totalElements(vector<int> &arr) {
        int n = arr.size();
        unordered_map<int, int> map;
        int start = 0, maxLen = 0;
        
        for(int end=0; end<n; end++) {
            map[arr[end]]++;
            while(map.size() > 2 && start < n) {
                map[arr[start]]--;
                
                if(map[arr[start]] == 0)
                    map.erase(arr[start]);
                    
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }
        
        return maxLen;
    }
};
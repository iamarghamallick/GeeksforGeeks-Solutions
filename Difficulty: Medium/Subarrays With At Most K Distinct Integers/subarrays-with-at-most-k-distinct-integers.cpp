class Solution {
  public:
    int countAtMostK(vector<int> &arr, int k) {
        int n = arr.size();
        unordered_map<int, int> map;
        int start = 0, count = 0;
        
        for(int end=0; end<n; end++) {
            map[arr[end]]++;
            
            while(map.size() > k) {
                map[arr[start]]--;
                
                if(map[arr[start]] == 0)
                    map.erase(arr[start]);
                    
                start++;
            }
            
            count += (end - start) + 1;
        }
        
        return count;
    }
};
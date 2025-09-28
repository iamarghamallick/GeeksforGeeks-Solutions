class Solution {
    public ArrayList<Integer> longestSubarray(int[] arr, int x) {
        int n = arr.length;
        int maxLen = 0;
        int begin = 0;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        
        int start = 0;
        for(int end=0; end<n; end++) {
            map.put(arr[end], map.getOrDefault(arr[end], 0) + 1);
            
            int minVal = map.firstKey();
            int maxVal = map.lastKey();
            
            if(maxVal - minVal <= x) {
                if(maxLen < end - start + 1) {
                    maxLen = end - start + 1;
                    begin = start;
                }
            } else {
                while(start < end && maxVal - minVal > x) {
                    map.put(arr[start], map.get(arr[start]) - 1);
                    
                    if(map.get(arr[start]) == 0)
                        map.remove(arr[start]);
                    
                    start++;
                    
                    minVal = map.firstKey();
                    maxVal = map.lastKey();
                }
            }
        }
        
        ArrayList<Integer> ans = new ArrayList<>();
        for(int i = begin; i < begin + maxLen; i++)
            ans.add(arr[i]);
        
        return ans;
    }
}
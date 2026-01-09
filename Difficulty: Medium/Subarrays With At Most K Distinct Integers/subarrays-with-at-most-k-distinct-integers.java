class Solution {
    public int countAtMostK(int arr[], int k) {
        int count = 0, i = 0, j = 0;
        HashMap<Integer, Integer> hm = new HashMap<>();
        
        while(i < arr.length) {
            hm.put(arr[i], hm.getOrDefault(arr[i], 0) + 1);
            while(hm.size() > k) {
               hm.put(arr[j], hm.getOrDefault(arr[j], 0) - 1); 
               if(hm.get(arr[j]) == 0) hm.remove(arr[j]);
               j++;
            }
            count += (i-j+1);
            i++;
        }
        
        return count;
    }
}

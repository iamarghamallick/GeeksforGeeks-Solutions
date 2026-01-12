class Solution {
    public ArrayList<Integer> maxOfSubarrays(int[] arr, int k) {
        int max = 0;
        ArrayList<Integer> list = new ArrayList<>();   
        for(int i=0; i<k; i++)
            if(max < arr[i])
                max = arr[i];
                
        list.add(max);
        int len = k;
        for(int i=0; i<arr.length-len; i++) {
            if(arr[i] == max) {
                max = 0;
                
                for(int j=i+1; j<=k; j++)
                    if(max < arr[j])
                        max = arr[j];
            }
            
            if(arr[k] > max) max = arr[k];
            list.add(max);
            k++;
        }
        
        return list;
        
        // ArrayList<Integer> ans = new ArrayList<>();
        // PriorityQueue<Integer> pq = new PriorityQueue<>(Collections.reverseOrder());
        
        // for(int i=0; i<k; i++) pq.add(arr[i]);
        // ans.add(pq.peek());
        
        // for(int i=k; i<arr.length; i++) {
        //     pq.remove(arr[i-k]);
        //     pq.add(arr[i]);
        //     ans.add(pq.peek());
        // }
        
        // return ans;
    }
}
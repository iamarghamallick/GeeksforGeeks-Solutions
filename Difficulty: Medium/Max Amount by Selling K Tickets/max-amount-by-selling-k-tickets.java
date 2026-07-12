class Solution {
    public int maxAmount(int[] arr, int k) {
        PriorityQueue<Integer> q = new PriorityQueue<>(Collections.reverseOrder());
        
        for(int i: arr) q.add(i);
        int mod = 1000000007;
        long ans = 0;
        while(!q.isEmpty() && k != 0) {
           int temp = q.poll();
           ans = (ans + temp) % mod;
           if(temp-1>0) q.add(temp-1);
           k--;
        }
        
        return (int) ans;
    }
}
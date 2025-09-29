class Solution {
    public int maxSubarrSum(int[] arr, int a, int b) {
        int n = arr.length;
        long[] prefix = new long[n + 1];
        
        for (int i = 0; i < n; i++)
            prefix[i + 1] = prefix[i] + arr[i];

        int ans = Integer.MIN_VALUE;
        Deque<Integer> dq = new LinkedList<>();

        for (int i = a; i <= n; i++) {
            while (!dq.isEmpty() && prefix[dq.peekLast()] >= prefix[i - a])
                dq.pollLast();
                
            dq.addLast(i - a);

            while (!dq.isEmpty() && dq.peekFirst() < i - b)
                dq.pollFirst();
                
            ans = Math.max(ans, (int)(prefix[i] - prefix[dq.peekFirst()]));
        }
        
        return ans;
    }
}
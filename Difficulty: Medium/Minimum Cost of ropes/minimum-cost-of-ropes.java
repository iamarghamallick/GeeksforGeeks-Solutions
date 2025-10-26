class Solution {
    public static int minCost(int[] arr) {
        if(arr.length == 1) return 0;
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        for(int num: arr) pq.add(num);
        int cost = 0;
        while(pq.size() > 1) {
            int r1 = pq.poll();
            int r2 = pq.poll();
            int sum = r1 + r2;
            cost += sum;
            pq.add(sum);
        }
        return cost;
    }
}
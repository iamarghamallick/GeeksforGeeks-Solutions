class Solution {
    public int startStation(int[] gas, int[] cost) {
        int n = gas.length;
        int totalGas = 0, totalCost = 0;
        for(int i=0; i<n; i++) {
            totalGas += gas[i];
            totalCost += cost[i];
        }
        if(totalGas < totalCost) return -1;
        int start = 0;
        while(start < n) {
            while(start < n && gas[start] < cost[start])
                start++;
            if(start >= n) return -1;
            int available = gas[start];
            for(int i=1; i<=n; i++) {
                int prev = (start + i - 1) % n;
                int curr = (start + i) % n;
                available = available - cost[prev] + gas[curr];
                if(curr == start) return start;
                if(available < cost[curr]) {
                    start = (curr + 1) % n;
                    break;
                }
            }
        }
        return -1;
    }
}
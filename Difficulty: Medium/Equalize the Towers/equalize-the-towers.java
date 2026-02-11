class Solution {
    public int calculateCost(int[] heights, int[] costs, int h) {
        int cost = 0;
        for(int i=0; i<heights.length; i++) {
            cost += Math.abs(heights[i] - h) * costs[i];
        }
        return cost;
    }
    
    public int minCost(int[] heights, int[] cost) {
        int low = Arrays.stream(heights).min().getAsInt();
        int high = Arrays.stream(heights).max().getAsInt();
        
        while(low <= high) {
            int mid = (low + high) >>> 1;
            int c0 = calculateCost(heights, cost, mid - 1);
            int c1 = calculateCost(heights, cost, mid);
            int c2 = calculateCost(heights, cost, mid + 1);
            
            if(c1 <= c0 && c1 <= c2) return c1;
            else if(c0 >= c1 && c1 >= c2) low = mid + 1;
            else high = mid - 1;
        }
        
        return -1;
    }
}

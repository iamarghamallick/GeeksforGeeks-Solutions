class Solution {
  public:
    int findCost(int h, vector<int>& heights, vector<int>& cost) {
        int ans = 0;
        
        for(int i=0; i<heights.size(); i++) {
            ans += cost[i] * abs(heights[i] - h);
        }
        
        return ans;
    }
    
    int minCost(vector<int>& heights, vector<int>& cost) {
        int minH = INT_MAX, maxH = INT_MIN;
        int ans;
        
        for(int h : heights) {
            minH = min(minH, h);
            maxH = max(maxH, h);
        }
        
        while(minH <= maxH) {
            int midH = minH + (maxH - minH) / 2;
            
            int leftCost = findCost(midH - 1, heights, cost);
            int midCost = findCost(midH, heights, cost);
            int rightCost = findCost(midH + 1, heights, cost);
            
            if(midCost <= leftCost && midCost <= rightCost) {
                ans = midCost;
                break;
            } else if(rightCost <= midCost && midCost <= leftCost) {
                minH = midH + 1;
            } else if(leftCost <= rightCost && leftCost <= midCost) {
                maxH = midH - 1;
            }
        }
        
        return ans;
    }
};

class Solution {
    public int minProd(int[] arr) {
        int prod = 1, neg = 0, zero = 0,
            minNegAbs = Integer.MAX_VALUE,
            minPos = Integer.MAX_VALUE;
        
        for(int num: arr) {
            if(num == 0) {
                zero++;
                continue;
            }
            
            prod *= num;
            
            if(num < 0) {
                neg++;
                minNegAbs = Math.min(minNegAbs, Math.abs(num));
            } else {
                minPos = Math.min(minPos, num);
            }
        }
        
        if (neg > 0) {
            if (neg % 2 == 1) {
                return prod;
            }

            return prod / (-minNegAbs);
        }

        if (zero > 0) {
            return 0;
        }

        return minPos;
    }
}
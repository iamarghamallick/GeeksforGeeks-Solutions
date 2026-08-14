class Solution {
    public boolean isPossible(int[] arr, int s, int x) {
        if(x == 0) {
            return true;
        }
        if(s > x) {
            return false;
        }
        
        int n = arr.length;
        ArrayList<Long> gArr = new ArrayList<>();
        long prefix = s;
        gArr.add(prefix);
        
        for(int i=1; i<=n; i++) {
            gArr.add(prefix + arr[i-1]);
            prefix += gArr.get(i);
            if(prefix > x) {
                break;
            }
        }
        
        for(int i=gArr.size() - 1; i>=0; i--) {
            if(gArr.get(i) <= x) {
                x -= gArr.get(i);
            }
        }
        
        return x == 0;
        
        // int n = arr.length;
        // int[] gArr = new int[n + 1];
        // int prefix = s;
        // gArr[0] = prefix;
        
        // for(int i=1; i<=n; i++) {
        //     gArr[i] = prefix + arr[i-1];
        //     prefix += gArr[i];
        // }
        
        // int[][] dp = new int[n+2][x+1];
        // for(int i=0; i<n+2; i++) {
        //     for(int j=0; j<x+1; j++) {
        //         dp[i][j] = -1;
        //     }
        // }
        
        // return subsetSum(0, n + 1, gArr, x, dp) == 1;
    }
    
    // private int subsetSum(int i, int n, int[] arr, int target, int[][] dp) {
    //     if(target == 0) {
    //         return 1;
    //     }
    //     if(i == n) {
    //         return 0;
    //     }
    //     if(dp[i][target] != -1) {
    //         return dp[i][target];
    //     }
    //     int take = (target - arr[i] >= 0) ? subsetSum(i+1, n, arr, target - arr[i], dp) : 0;
    //     int notTake = subsetSum(i+1, n, arr, target, dp);
    //     return dp[i][target] = Math.max(take, notTake);
    // }
}
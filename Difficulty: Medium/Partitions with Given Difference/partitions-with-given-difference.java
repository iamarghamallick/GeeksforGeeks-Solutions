class Solution {
    int countSubsets(int [] arr, int sum){
        int n = arr.length;
        int [][] dp = new int[n+1][sum+1];
        for(int i=0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][sum];
    }
    
    int countPartitions(int[] arr, int d) {
       int n = arr.length;
       int totalsum = 0;
       for(int num : arr){
           totalsum += num;
       }
       if ((totalsum + d) % 2 != 0 || d > totalsum) return 0;
       int sum = (d + totalsum)/2;
       return countSubsets(arr,sum);
    }
}

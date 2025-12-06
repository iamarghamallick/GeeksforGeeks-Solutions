
class Solution {
    int dp[][] = new int[1001][1001];
    
    public int maximumAmount(int arr[]) {
        int n = arr.length;
        return solve(arr, n, 0, n-1);
    }
    
    private int solve(int arr[], int n, int i, int j) {
        if(i > j || i >= n || j < 0)
            return 0;
            
        if(dp[i][j] != 0)
            return dp[i][j];
        
        int option1 = arr[i] + Math.min(solve(arr, n, i+2, j), solve(arr, n, i+1, j-1));
        int option2 = arr[j] + Math.min(solve(arr, n, i+1, j-1), solve(arr, n, i, j-2));
        
        return dp[i][j] = Math.max(option1, option2);
    }
}

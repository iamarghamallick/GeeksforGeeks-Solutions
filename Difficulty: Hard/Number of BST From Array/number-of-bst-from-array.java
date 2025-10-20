class Solution {
    // Function to compute catalan number upto n
    public void findCatalan(int n, int[] dp) {
        if (n == 0) { // edge case
            dp[0] = 1;
            return;
        }
        
        // DP using Tabulation
        
        // Base cse : catalan of 0 and 1 = 1
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i=2; i<n+1; i++){
            for(int j=0; j<i; j++){
                // C(i) = Σ (C(j) * C(i-j-1)) 
                dp[i] += dp[j] * dp[i-j-1];
            }
        }
    }
    
    public ArrayList<Integer> countBSTs(int[] arr) {
        ArrayList<Integer> ans = new ArrayList<>(); // to store ans
        
        int n = arr.length;
        
        // dp[i] will store the ith Catalan number
        int[] dp = new int[n+1]; // for Tabulation
        findCatalan(n-1, dp); // precompute catalan number for each nodes
        
        
        // Number of bst's when arr[i] is the root will be:
        // Number of nodes to go in left subtree * Number of nodes to go in right subtree
        for (int i = 0; i < n; i++) { // i = curr root
            int left = 0; // number of elements to go in left subtree
            int right = 0; // number of elements to go in right subtree
            for (int j = 0; j < n; j++) {
                if (arr[j] < arr[i]) left++; // count elements smaller than arr[i]
                else if (arr[j] > arr[i]) right++; // count elements greater than arr[i]
            }
            ans.add(dp[left] * dp[right]); // add possible BST's for each elements in ans
        }
        return ans;
    }
}
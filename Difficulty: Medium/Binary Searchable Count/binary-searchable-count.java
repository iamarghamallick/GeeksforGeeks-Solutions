class Solution {
    public int binarySearchable(int[] nums) {
        
        int n = nums.length;
        return helper(nums, 0, n -1, -(int)1e9, (int)1e9);
    }
    
    private int helper(int[] nums, int l, int r, int mini, int maxi) {
        if (l > r) return 0;
        int res = 0;
        
        int m = l + (r - l) / 2;
        if (mini < nums[m] && nums[m] < maxi) res = 1;
        
        int left = helper(nums, l, m -1, mini, Math.min(nums[m], maxi));
        int right = helper(nums, m +1, r, Math.max(mini, nums[m]), maxi);
        
        return res + left + right;
    }
};
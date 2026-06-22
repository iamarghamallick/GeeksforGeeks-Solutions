class Solution {
    public int maxArea(List<Integer> height) {
        int left = 0;
        int right = height.size() - 1;
        int ans = 0;
        while(left <= right) {
            int lh = height.get(left);
            int rh = height.get(right);
            ans = Math.max(ans, Math.min(lh, rh) * (right - left - 1));
            if(lh < rh) {
                left++;
            } else {
                right--;
            }
        }
        return ans;
    }
}
class Solution {
    public int kokoEat(int[] arr, int k) {
        int left = 1, right = 0;

        // Find maximum pile size
        for (int pile : arr) {
            right = Math.max(right, pile);
        }

        // Worst-case result
        int res = right;

        // Binary search on eating speed
        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (canFinish(arr, k, mid)) {
                res = mid;          // possible speed, try smaller
                right = mid - 1;
            } else {
                left = mid + 1;     // too slow, try bigger
            }
        }

        return res;
    }

    public boolean canFinish(int[] arr, int k, int s) {
        int hours = 0;

        for (int pile : arr) {
            // Ceil(pile / s)
            hours += (pile + s - 1) / s;

            if (hours > k) {
                return false;
            }
        }

        return true;
    }
}

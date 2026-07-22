class Solution {

    int find(List<Integer> list, int num) {
        int ans = -1;
        int low = 0;
        int high = list.size() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            if (list.get(mid) >= num) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }

    public int minDeletions(int[] arr) {

        int n = arr.length;
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < n; i++) {
            int num = arr[i];

            if (list.size() == 0 || list.get(list.size() - 1) < num) {
                list.add(num);
            } else {
                int idx = find(list, num);
                list.set(idx, num);
            }
        }

        return n - list.size();
    }
}
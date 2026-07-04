class Solution {

    static int merge(int left, int mid, int right, int[] prefix) {
        int i = left;
        int j = mid + 1;

        ArrayList<Integer> arr = new ArrayList<>();
        int cnt = 0;

        while (i <= mid && j <= right) {
            if (prefix[i] < prefix[j]) {
                arr.add(prefix[i++]);
                cnt += right - j + 1;
            } else {
                arr.add(prefix[j++]);
            }
        }

        while (i <= mid) {
            arr.add(prefix[i++]);
        }

        while (j <= right) {
            arr.add(prefix[j++]);
        }

        for (int k = left; k <= right; k++) {
            prefix[k] = arr.get(k - left);
        }

        return cnt;
    }

    static int mergeSort(int i, int j, int[] prefix) {
        if (i == j) {
            return 0;
        }

        int mid = (i + j) / 2;
        int cnt = 0;

        cnt += mergeSort(i, mid, prefix);
        cnt += mergeSort(mid + 1, j, prefix);
        cnt += merge(i, mid, j, prefix);

        return cnt;
    }

    public int countSubstring(String s) {
        int n = s.length();
        int[] prefix = new int[n + 1];

        for (int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + (s.charAt(i) == '0' ? -1 : 1);
        }

        return mergeSort(0, n, prefix);
    }
}
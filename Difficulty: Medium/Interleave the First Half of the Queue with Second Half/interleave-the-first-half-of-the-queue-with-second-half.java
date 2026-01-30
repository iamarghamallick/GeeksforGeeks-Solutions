class Solution {
    public void rearrangeQueue(Queue<Integer> q) {
        if (q == null || q.isEmpty()) return;

        int n = q.size();
        if (n % 2 != 0) {
            n = n - 1;
        }

        int[] arr = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = q.poll();
        }

        if (q.size() % 2 != 0) {
            q.poll();
        }

        int i = 0;
        int j = n / 2;
        int pos = 0;

        while (i <= n / 2 && j < n) {
            if (pos % 2 == 0) {
                q.offer(arr[i]);
                i++;
            } else {
                q.offer(arr[j]);
                j++;
            }
            pos++;
        }
    }
}

class Solution {
    private long[] tree;

    private int n;

 

    public ArrayList<Long> RangeLCMQuery(int[] arr, int[][] queries) {

        n = arr.length;

        tree = new long[4 * n];

        build(arr, 0, 0, n - 1);

 

        ArrayList<Long> ans = new ArrayList<>();

        for (int[] q : queries) {

            if (q[0] == 1) {

                // Update Query: [1, index, value]

                update(0, 0, n - 1, q[1], q[2]);

            } else {

                // Range Query: [2, left, right]

                ans.add(query(0, 0, n - 1, q[1], q[2]));

            }

        }

        return ans;

    }

 

    private long gcd(long a, long b) {

        while (b > 0) {

            a %= b;

            long temp = a;

            a = b;

            b = temp;

        }

        return a;

    }

 

    private long lcm(long a, long b) {

        if (a == 0 || b == 0) return 0;

        return (a * b) / gcd(a, b);

    }

 

    private void build(int[] arr, int node, int start, int end) {

        if (start == end) {

            tree[node] = arr[start];

            return;

        }

        int mid = (start + end) / 2;

        build(arr, 2 * node + 1, start, mid);

        build(arr, 2 * node + 2, mid + 1, end);

        tree[node] = lcm(tree[2 * node + 1], tree[2 * node + 2]);

    }

 

    private void update(int node, int start, int end, int idx, int val) {

        if (start == end) {

            tree[node] = val;

            return;

        }

        int mid = (start + end) / 2;

        if (idx <= mid) {

            update(2 * node + 1, start, mid, idx, val);

        } else {

            update(2 * node + 2, mid + 1, end, idx, val);

        }

        tree[node] = lcm(tree[2 * node + 1], tree[2 * node + 2]);

    }

 

    private long query(int node, int start, int end, int l, int r) {

        if (r < start || end < l) {

            return 1; // Neutral element for LCM

        }

        if (l <= start && end <= r) {

            return tree[node];

        }

        int mid = (start + end) / 2;

        long leftLcm = query(2 * node + 1, start, mid, l, r);

        long rightLcm = query(2 * node + 2, mid + 1, end, l, r);

        return lcm(leftLcm, rightLcm);

    }
}
class Solution {
    public static void rotateDeque(Deque<Integer> dq, int type, int k) {
        k = k % dq.size();
        while(k-- > 0) {
            if(type == 1) {
                int n = dq.removeLast();
                dq.addFirst(n);
            } else {
                int n = dq.removeFirst();
                dq.addLast(n);
            }
        }
    }
}
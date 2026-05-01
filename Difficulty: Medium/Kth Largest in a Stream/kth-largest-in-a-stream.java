class Solution {
    static ArrayList<Integer> kthLargest(int[] arr, int k) {
        ArrayList<Integer> ans = new ArrayList<>();
        Queue<Integer> q = new PriorityQueue<>();
        for(int i=0; i<k-1; i++) {
            q.offer(arr[i]);
            ans.add(-1);
        }
        for(int i=k-1; i<arr.length; i++) {
            q.offer(arr[i]);
            if(q.size() > k) {
                q.poll();
            }
            ans.add(q.peek());
        }
        return ans;
    }
}
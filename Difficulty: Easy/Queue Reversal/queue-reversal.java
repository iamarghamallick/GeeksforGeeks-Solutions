class Solution {
    public void reverseQueue(Queue<Integer> q) {
        int n = q.size();
        ArrayList<Integer> arr = new ArrayList<>();
        while(!q.isEmpty()) arr.add(q.remove());
        for(int i=n-1; i>=0; i--) q.add(arr.get(i));
    }
}
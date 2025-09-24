class SpecialQueue {
    Queue<Integer> q;
    PriorityQueue<Integer> minHeap;
    PriorityQueue<Integer> maxHeap;

    public SpecialQueue() {
        q = new LinkedList<>();
        minHeap = new PriorityQueue<>();
        maxHeap = new PriorityQueue<>(Collections.reverseOrder());
    }

    public void enqueue(int x) {
        q.add(x);
        minHeap.add(x);
        maxHeap.add(x);
    }

    public void dequeue() {
        int x = q.remove();
        minHeap.remove(x);
        maxHeap.remove(x);
    }

    public int getFront() {
        return q.peek();
    }

    public int getMin() {
        return minHeap.peek();
    }

    public int getMax() {
        return maxHeap.peek();
    }
}
class Solution {
	public int minComputation(int[] files) {
		PriorityQueue<Integer> pq = new PriorityQueue<>();
		
		for (int file: files) {
			pq.offer(file);
		}
		
		int totalCost = 0;
		
		while (pq.size() >= 2) {
			int a = pq.poll();
			int b = pq.poll();
			
			int cost = a + b;
			
			pq.offer(cost);
			totalCost += cost;
		}
		
		return totalCost;
	}
}

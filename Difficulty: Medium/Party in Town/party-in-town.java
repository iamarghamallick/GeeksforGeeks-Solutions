class Solution {
	public int partyHouse(ArrayList<ArrayList<Integer>> adj) {
		int n = adj.size();
		
		// Find one endpoint of the diameter
		int[] first = bfs(adj, 0);
		int farthestNode = first[0];
		
		// Find the diameter
		int[] second = bfs(adj, farthestNode);
		int diameter = second[1];
		
		// Minimum possible maximum distance
		return (diameter + 1) / 2;
	}
	
	private int[] bfs(ArrayList<ArrayList<Integer>> adj, int start) {
		int n = adj.size();
		boolean[] visited = new boolean[n];
		int[] dist = new int[n];
		
		Queue<Integer> q = new LinkedList<>();
		q.offer(start);
		visited[start] = true;
		
		int farthestNode = start;
		int maxDist = 0;
		
		while (!q.isEmpty()) {
			int node = q.poll();
			
			for (int next : adj.get(node)) {
				// Convert house number (1-based) to index (0-based)
				next--;
				
				if (!visited[next]) {
					visited[next] = true;
					dist[next] = dist[node] + 1;
					q.offer(next);
					
					if (dist[next] > maxDist) {
						maxDist = dist[next];
						farthestNode = next;
					}
				}
			}
		}
		
		return new int[] {farthestNode, maxDist};
	}
}

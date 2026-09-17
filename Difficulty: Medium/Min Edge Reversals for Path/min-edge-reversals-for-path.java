class Solution {
	public int minimumEdgeReversal(int[][] edges, int n, int src, int dst) {
		ArrayList<ArrayList<int[]>> adj = new ArrayList<>();
		
		for (int i = 0; i <= n; i++)
			adj.add(new ArrayList<>());
		
		// Create adjacency list with both directions.
		for (int[] edge : edges) {
			int u = edge[0];
			int v = edge[1];
			
			// Original direction requires no reversal.
			adj.get(u).add(new int[] {v, 0});
			
			// Reverse direction requires one reversal.
			adj.get(v).add(new int[] {u, 1});
		}
		
		// Store the minimum reversals required to reach each node.
		int[] dist = new int[n + 1];
		Arrays.fill(dist, Integer.MAX_VALUE);
		
		Deque<Integer> dq = new ArrayDeque<>();
		
		// Distance of source is 0.
		dist[src] = 0;
		dq.addFirst(src);
		
		// Apply 0-1 BFS.
		while (!dq.isEmpty()) {
			int node = dq.removeFirst();
			
			// Explore all adjacent nodes.
			for (int[] edge : adj.get(node)) {
				int next = edge[0];
				int cost = edge[1];
				
				// Update the distance if a better path is found.
				if (dist[node] + cost < dist[next]) {
					dist[next] = dist[node] + cost;
					
					// Process zero-cost edges first.
					if (cost == 0)
						dq.addFirst(next);
					else
						dq.addLast(next);
				}
			}
		}
		
		// No path exists from src to dst.
		if (dist[dst] == Integer.MAX_VALUE)
			return - 1;
		
		return dist[dst];
	}
}

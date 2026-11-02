class Solution {
	public int largestSumCycle(int[] edge) {
		int n = edge.length;
		long ans = -1;
		
		int[] state = new int[n];
		int[] parent = new int[n];
		Arrays.fill(parent, -1);
		
		// Try starting DFS from every unvisited cell
		for (int i = 0; i < n; i++) {
			if (state[i] == 0) {
				ans = Math.max(ans, dfs(i, edge, state, parent));
			}
		}
		
		return (int)ans;
	}
	
	private long dfs(int node, int[] edge, int[] state, int[] parent) {
		// Mark the current cell as being visited
		state[node] = 1;
		
		int next = edge[node];
		
		// No outgoing edge
		if (next == -1) {
			state[node] = 2;
			return - 1;
		}
		
		// Visit the next cell if it is unvisited
		if (state[next] == 0) {
			parent[next] = node;
			
			long sum = dfs(next, edge, state, parent);
			
			// Mark the current cell as completely processed
			state[node] = 2;
			
			return sum;
		}
		
		// A cycle is found if the next cell is in the
		// current path
		if (state[next] == 1) {
			long sum = next;
			int cur = node;
			
			// Calculate the sum of the cycle
			while (cur != next) {
				sum += cur;
				cur = parent[cur];
			}
			
			// Mark the current cell as completely processed
			state[node] = 2;
			
			return sum;
		}
		
		// The next cell is already completely processed
		state[node] = 2;
		
		return - 1;
	}
}

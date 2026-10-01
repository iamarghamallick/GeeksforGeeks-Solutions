class Solution {
	// DFS to find the completion time of a module.
	public int dfs(int node, int[][] adj, int[] duration,
	int[] state, int[] dp, boolean[] cycle) {
		
		// Cycle detected.
		if (state[node] == 1) {
			cycle[0] = true;
			return 0;
		}
		
		// Already calculated.
		if (state[node] == 2)
			return dp[node];
		
		state[node] = 1;
		
		int maxTime = 0;
		
		// Find the maximum time among dependent modules.
		for (int next : adj[node]) {
			maxTime
			= Math.max(maxTime, dfs(next, adj, duration,
			state, dp, cycle));
		}
		
		state[node] = 2;
		
		// Add the current module's duration.
		dp[node] = duration[node] + maxTime;
		
		return dp[node];
	}
	
	public int minTime(int[] duration, int[][] dependencies) {
		
		int n = duration.length;
		
		// Build the dependency graph.
		int[][] adj = new int[n][];
		for (int i = 0; i < n; i++) {
			adj[i] = new int[0];
		}
		for (int[] edge : dependencies) {
			List<Integer> temp = new ArrayList<>();
			for (int t : adj[edge[0]]) {
				temp.add(t);
			}
			temp.add(edge[1]);
			adj[edge[0]] = new int[temp.size()];
			for (int i = 0; i < temp.size(); i++) {
				adj[edge[0]][i] = temp.get(i);
			}
		}
		
		// 0 = unvisited, 1 = currently visiting, 2 =
		// completed.
		int[] state = new int[n];
		
		// Store the calculated completion time.
		int[] dp = new int[n];
		
		boolean[] cycle = new boolean[1];
		int res = 0;
		
		// Calculate completion time for every module.
		for (int i = 0; i < n; i++) {
			res = Math.max(res, dfs(i, adj, duration, state,
			dp, cycle));
		}
		
		// If a cycle exists, project cannot be completed.
		if (cycle[0])
			return - 1;
		
		return res;
	}
}

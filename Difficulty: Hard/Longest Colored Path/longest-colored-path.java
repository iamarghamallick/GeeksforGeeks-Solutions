class Solution {
	// Perform a bottom-up DFS to calculate the best path
	// contribution coming from each node's subtree.
	public void root(List<List<Integer> > adj, String s,
	int[][] sa, int node, int par)
	{
		int ra = 0, ba = 0;
		
		// Process all children of the current node.
		for (int it : adj.get(node)) {
			if (it == par)
				continue;
			
			// Calculate DP values for the child subtree.
			root(adj, s, sa, it, node);
			
			// Store the maximum possible contribution
			// for a path ending at a Red node.
			ra = Math.max(ra, sa[it][0]);
			ra = Math.max(ra, sa[it][1]);
			
			// Store the maximum possible contribution
			// for a path ending at a Blue node.
			ba = Math.max(ba, sa[it][1]);
		}
		
		// Calculate the DP values based on the
		// color of the current node.
		if (s.charAt(node) == 'R') {
			sa[node][0] = ra + 1;
			sa[node][1] = 0;
		}
		else {
			sa[node][0] = ba + 1;
			sa[node][1] = ba + 1;
		}
	}
	
	// Reroot the tree to include contributions
	// coming from the parent and sibling subtrees.
	public void reroot(List<List<Integer> > adj, String s,
	int[][] ans, int[][] sa, int node,
	int par, int redPar, int bluePar)
	{
		
		// Calculate the best answer for the current node
		// by considering both subtree and parent
		// contributions.
		if (s.charAt(node) == 'R') {
			ans[node][0]
			= Math.max(sa[node][0], 1 + redPar);
			ans[node][1] = 0;
		}
		else {
			ans[node][0]
			= Math.max(sa[node][0], 1 + bluePar);
			ans[node][1]
			= Math.max(sa[node][1], 1 + bluePar);
		}
		
		// Find the largest and second-largest contributions
		// from all child subtrees.
		int fr = redPar, sr = redPar;
		int fb = bluePar, sb = bluePar;
		
		for (int it : adj.get(node)) {
			if (it == par)
				continue;
			
			// Maintain the two largest Red contributions.
			if (sa[it][0] > fr) {
				sr = fr;
				fr = sa[it][0];
			}
			else if (sa[it][0] > sr) {
				sr = sa[it][0];
			}
			
			// Maintain the two largest Blue contributions.
			if (sa[it][1] > fb) {
				sb = fb;
				fb = sa[it][1];
			}
			else if (sa[it][1] > sb) {
				sb = sa[it][1];
			}
		}
		
		// Pass the best contribution excluding the current
		// child while rerooting the tree at every child.
		for (int it : adj.get(node)) {
			if (it == par)
				continue;
			
			int newRed = 0, newBlue = 0;
			
			if (s.charAt(node) == 'R') {
				// Use the best Red contribution
				// that does not come from this child.
				newRed = 1;
				
				if (sa[it][0] == fr)
					newRed += sr;
				else
					newRed += fr;
				
				newBlue = 0;
			}
			else {
				// Use the best Blue contribution
				// that does not come from this child.
				newRed = 1;
				
				if (sa[it][1] == fb)
					newRed += sb;
				else
					newRed += fb;
				
				newBlue = newRed;
			}
			
			// Reroot the tree at the current child.
			reroot(adj, s, ans, sa, it, node, newRed,
			newBlue);
		}
	}
	
	public int longestPath(String s, int[][] edges)
	{
		int n = s.length();
		
		// Build the adjacency list of the tree.
		List<List<Integer> > adj = new ArrayList<>();
		
		for (int i = 0; i < n; i++)
			adj.add(new ArrayList<>());
		
		for (int[] e : edges) {
			adj.get(e[0] - 1).add(e[1] - 1);
			adj.get(e[1] - 1).add(e[0] - 1);
		}
		
		// Index 0 represents Red and index 1 represents
		// Blue.
		int[][] subTreeAns = new int[n][2];
		
		// Calculate DP values using a bottom-up traversal.
		root(adj, s, subTreeAns, 0, -1);
		
		int[][] ans = new int[n][2];
		
		// Reroot the tree to consider paths in all
		// directions.
		reroot(adj, s, ans, subTreeAns, 0, -1, 0, 0);
		
		int res = 0;
		
		// Find the maximum valid path length.
		for (int i = 0; i < n; i++)
			res = Math.max(res,
		Math.max(ans[i][0], ans[i][1]));
		
		return res;
	}
}

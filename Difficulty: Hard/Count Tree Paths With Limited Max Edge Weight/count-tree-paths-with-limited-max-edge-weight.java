class Solution {
	
	int ans;
	
	// Find the representative of a set.
	int root(int x, int[] parent) {
		if (parent[x] == x)
			return x;
		
		return parent[x] = root(parent[x], parent);
	}
	
	// Union two components.
	void Union(int a, int b, int[] parent, int[] sz) {
		int ra = root(a, parent);
		int rb = root(b, parent);
		
		// Already in the same component.
		if (ra == rb)
			return;
		
		// Union by size.
		if (sz[ra] < sz[rb]) {
			int temp = ra;
			ra = rb;
			rb = temp;
		}
		
		// Count paths between the two components.
		ans += sz[ra] * sz[rb];
		
		parent[rb] = ra;
		sz[ra] += sz[rb];
	}
	
	public ArrayList<Integer> maximumWeight(int n, int[][] edges, int[] queries) {
		ans = 0;
		
		int[] parent = new int[n + 1];
		int[] sz = new int[n + 1];
		Arrays.fill(sz, 1);
		
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
		}
		
		// Store {weight, u, v}.
		ArrayList<int[]> wt = new ArrayList<>();
		
		for (int[] e : edges) {
			wt.add(new int[] { e[2], e[0], e[1] });
		}
		
		// Sort edges by weight.
		wt.sort((a, b) -> Integer.compare(a[0], b[0]));
		
		// Store the number of valid paths for each weight.
		TreeMap<Integer, Integer> mp = new TreeMap<>();
		
		int i = 0;
		
		while (i < wt.size()) {
			int weight = wt.get(i)[0];
			
			// Process all edges having the same weight.
			while (i < wt.size()
				 && wt.get(i)[0] == weight) {
				int u = wt.get(i)[1];
				int v = wt.get(i)[2];
				
				Union(u, v, parent, sz);
				i++;
			}
			
			// Store the answer after processing this
			// weight.
			mp.put(weight, ans);
		}
		
		ArrayList<Integer> res = new ArrayList<>();
		
		// Process every query.
		for (int x : queries) {
			// Find the greatest weight <= x.
			Integer key = mp.floorKey(x);
			
			if (key == null)
				res.add(0);
			else
				res.add(mp.get(key));
		}
		
		return res;
	}
};

class Solution {
	
	public int goodIndices(int[] arr) {
		int n = arr.length;
		int answer = 0;
		
		// 0 = unvisited, 1 = visiting, 2 = good, 3 = bad.
		int[] state = new int[n];
		
		// Check every index using DFS with memoization.
		for (int i = 0; i < n; i++) {
			if (dfs(i, arr, state))
				answer++;
		}
		
		return answer;
	}
	
	private boolean dfs(int index, int[] arr, int[] state) {
		int n = arr.length;
		
		// The current index is outside the array.
		if (index < 0 || index >= n)
			return true;
		
		// A zero jump is a dead end.
		if (arr[index] == 0)
			return false;
		
		// The index is already known to be good.
		if (state[index] == 2)
			return true;
		
		// The index is already known to be bad.
		if (state[index] == 3)
			return false;
		
		// A cycle is detected.
		if (state[index] == 1)
			return false;
		
		// Mark the current index as visiting.
		state[index] = 1;
		
		// Follow the next index.
		int nextIndex = index + arr[index];
		
		boolean good = dfs(nextIndex, arr, state);
		
		// Store the result for future traversals.
		state[index] = good ? 2 : 3;
		
		return good;
	}
}

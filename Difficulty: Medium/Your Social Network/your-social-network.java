class Solution {
	public ArrayList<ArrayList<Integer>> socialNetwork(int[] arr) {
		int n = arr.length + 1;
		int[][] dist = new int[n + 1][n + 1];

		ArrayList<ArrayList<Integer>> result = new ArrayList<>();

		for (int i = 2; i <= n; i++) {
			int friend = arr[i - 2];
			dist[i][friend] = 1;

			for (int j = 1; j < friend; j++) {
				if (dist[friend][j] > 0) {
					dist[i][j] = dist[friend][j] + 1;
				}
			}

			for (int j = 1; j < i; j++) {
				if (dist[i][j] > 0) {
					ArrayList<Integer> tuple = new ArrayList<>();
					tuple.add(i);
					tuple.add(j);
					tuple.add(dist[i][j]);
					result.add(tuple);
				}
			}
		}

		return result;
	}
}

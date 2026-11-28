class Solution {
  public boolean checkPath(ArrayList<ArrayList<Integer>> adj, int u, int v) {
    int n = adj.size();
    Queue<Integer> q = new LinkedList<>();
    boolean[] visited = new boolean[n];

    q.offer(u);
    visited[u] = true;

    while (!q.isEmpty()) {
      int node = q.poll();

      if (node == v) {
        return true;
      }

      for (Integer next : adj.get(node)) {
        if (!visited[next]) {
          q.offer(next);
          visited[next] = true;
        }
      }
    }

    return false;
  }
}
class Solution {
    public ArrayList<Integer> safeNodes(int V, int[][] edges) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for (int i = 0; i < V; i++) graph.add(new ArrayList<>());
        for (int[] edge : edges) graph.get(edge[0]).add(edge[1]);

        int[] visited = new int[V];
        int[] pathVis = new int[V];
        int[] safe = new int[V];

        for (int i = 0; i < V; i++) {
            if (visited[i] == 0) dfs(i, graph, visited, pathVis, safe);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < V; i++)
            if (safe[i] == 1) ans.add(i);

        return ans;
    }

    private boolean dfs(int node, ArrayList<ArrayList<Integer>> graph,
                        int[] visited, int[] pathVis, int[] safe) {

        visited[node] = 1;
        pathVis[node] = 1;

        for (int nei : graph.get(node)) {
            if (visited[nei] == 0) {
                if (dfs(nei, graph, visited, pathVis, safe))
                    return true; // cycle found
            } else if (pathVis[nei] == 1) {
                return true; // back edge → cycle
            }
        }

        // if no cycle from this node
        safe[node] = 1;
        pathVis[node] = 0;
        return false;
    }
}
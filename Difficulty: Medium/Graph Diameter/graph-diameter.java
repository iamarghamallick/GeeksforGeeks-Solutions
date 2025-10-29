class Solution {
    public int diameter(int V, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0; i<V; i++) graph.add(new ArrayList<>());
        for(int[] e: edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        int farthestNode = bfs(0, graph, V)[0];
        int ans = bfs(farthestNode, graph, V)[1];
        
        return ans;
    }
    
    private int[] bfs(int node, List<List<Integer>> graph, int V) {
        Queue<Integer> q = new LinkedList<>();
        boolean visited[] = new boolean[V];
        int[] dist = new int[V];
        
        q.add(node);
        visited[node] = true;
        dist[node] = 0;
        
        while(!q.isEmpty()) {
            int temp = q.poll();
            
            for(int nei: graph.get(temp)) {
                if(!visited[nei]) {
                    visited[nei] = true;
                    q.add(nei);
                    dist[nei] = dist[temp] + 1;
                }
            }
        }
        
        int maxDist = 0;
        int farthestNode = node;
        for(int i=0; i<V; i++) {
            if(dist[i] > maxDist) {
                maxDist = dist[i];
                farthestNode = i;
            }
        }
        
        return new int[] { farthestNode, maxDist };
    }
}
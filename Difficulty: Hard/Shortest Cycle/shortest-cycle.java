class Solution {
    public int shortCycle(int V, int[][] edges) {
        List<List<Integer>> graph = new ArrayList<>();
        for(int i=0; i<V; i++) graph.add(new ArrayList<>());
        
        for(int[] e: edges) {
            graph.get(e[0]).add(e[1]);
            graph.get(e[1]).add(e[0]);
        }
        
        int ans = Integer.MAX_VALUE;
        
        for(int start = 0; start < V; start++) {
            Queue<Integer> q = new LinkedList<>();
            boolean[] visited = new boolean[V];
            int[] dist = new int[V];
            q.add(start);
            dist[start] = 0;
            visited[start] = true;
            
            while(!q.isEmpty()) {
                int node = q.poll();
                for(int nei: graph.get(node)) {
                    if(!visited[nei]) {
                        q.add(nei);
                        dist[nei] = dist[node] + 1;
                        visited[nei] = true;
                    } else if(dist[nei] >= dist[node]) {
                        ans = Math.min(ans, dist[node] + dist[nei] + 1);
                    }
                }
            }
        }
        
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}
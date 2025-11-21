class Solution {
    class Node{
        int u;
        int v;
        int wt;
        Node(int u, int v, int wt){
            this.u=u;
            this.v=v;
            this.wt=wt;
        }
    }
    
    class Pair implements Comparable<Pair>{
        int vertex;
        int wt;
        Pair(int vertex, int wt){
            this.vertex=vertex;
            this.wt=wt;
        }
        public int compareTo(Pair p2){
            // min-heap based on distance
            return this.wt-p2.wt;
        }
    }
    
    public void dijkstra(int src, ArrayList<Node>[] graph, int[] dist){
        PriorityQueue<Pair> pq = new PriorityQueue<>();
        pq.add(new Pair(src, 0));
        
        while(!pq.isEmpty()){
            Pair curr = pq.poll();
            int u = curr.vertex;
            
            for(Node neighbour : graph[curr.vertex]){
                int v = neighbour.v;
                int wt = neighbour.wt;
                
                if(dist[u]!=Integer.MAX_VALUE && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                    pq.add(new Pair(v, dist[v]));
                }
            }
        }
    }
    public int shortestPath(int V, int a, int b, int[][] edges) {
        
        // Make a adjacency list for given edges
        @SuppressWarnings("unchecked")
        ArrayList<Node>[] graph = new ArrayList[V];
        for(int i=0; i<V; i++){
            graph[i] = new ArrayList<>();
        }
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            graph[u].add(new Node(u, v, wt));
            graph[v].add(new Node(v, u, wt));
        }
        
        
        // Dijkstra from a
        int[] distA = new int[V]; // distA[i] will store shortest dist to node i from src = A using only straight edges
        Arrays.fill(distA, Integer.MAX_VALUE);
        distA[a] = 0;
        dijkstra(a, graph, distA);
        
        
        // Dijkstra from b
        int[] distB = new int[V]; // distB[i] will store shortest dist to node i from src = B using only straight edges
        Arrays.fill(distB, Integer.MAX_VALUE);
        distB[b] = 0;
        dijkstra(b, graph, distB);
        
        
        int shortest = Integer.MAX_VALUE; // will store shortest path from a to b using atmost 1 curved edge
        
        // Try using a single curved edge (w2) in both directions
        for(int i=0; i<edges.length; i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int cwt = edges[i][3]; // curved edge weight
            
            // Case 1: a → ... → u →(curved)→ v → ... → b
            if(distA[u]!=Integer.MAX_VALUE && distB[v]!=Integer.MAX_VALUE){
                int currPath = distA[u] + cwt + distB[v];
                shortest = Math.min(shortest, currPath);
            }
            // Case 2: a → ... → v →(curved)→ u → ... → b
            if(distB[u]!=Integer.MAX_VALUE && distA[v]!=Integer.MAX_VALUE){
                int currPath = distB[u] + cwt + distA[v];
                shortest = Math.min(shortest, currPath);
            }
        }
        
        // Case 3: a → ... → v → u → ... → b (no curved edge used)
        shortest = Math.min(shortest, distA[b]); // using 0 curved edge
        return shortest==Integer.MAX_VALUE? -1 : shortest;
    }
}
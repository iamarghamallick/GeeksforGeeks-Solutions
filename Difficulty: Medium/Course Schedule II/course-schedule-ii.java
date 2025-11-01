class Solution {
    public ArrayList<Integer> findOrder(int n, int[][] prerequisites) {
        ArrayList<ArrayList<Integer>> graph = new ArrayList<>();
        for(int i=0; i<n; i++)
            graph.add(new ArrayList<>());
        for(int[] pre: prerequisites)
            graph.get(pre[1]).add(pre[0]);
            
        int[] indegree = new int[n];
        for(int i=0; i<n; i++)
            for(int it: graph.get(i))
                indegree[it]++;
                
        Queue<Integer> q = new LinkedList<>();
        for(int i=0; i<n; i++) 
            if(indegree[i] == 0)
                q.add(i);
                
        ArrayList<Integer> topo = new ArrayList<>();
        while(!q.isEmpty()) {
            int node = q.poll();
            topo.add(node);
            for(int nei: graph.get(node)) {
                indegree[nei]--;
                if(indegree[nei] == 0)
                    q.add(nei);
            }
        }
        
        return topo.size() == n ? topo : new ArrayList<>();
    }
}
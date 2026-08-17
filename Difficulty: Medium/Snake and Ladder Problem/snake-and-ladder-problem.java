class Solution {
    public int minThrows(int n, int[] lad, int[] sn) {
        HashMap<Integer, Integer> map = new HashMap<>();
        for(int i=0; i<lad.length; i+=2) {
            map.put(lad[i], lad[i+1]);
        }
        for(int i=0; i<sn.length; i+=2) {
            map.put(sn[i], sn[i+1]);
        }
        
        boolean[] visited = new boolean[n*n + 1];
        
        Queue<int[]> q = new LinkedList<>();
        q.offer(new int[]{1, 0}); // {pos, dist}
        visited[1] = true;
        
        while(!q.isEmpty()) {
            int[] curr = q.poll();
            int pos = curr[0];
            int dist = curr[1];
            
            if(pos == n*n) {
                return dist;
            }
            
            for(int nextPos = pos + 1; nextPos <= Math.min(pos + 6, n*n); nextPos++) {
                if(!visited[nextPos]) {
                    visited[nextPos] = true;
                    
                    int newPos = map.containsKey(nextPos) ? map.get(nextPos) : nextPos;
                    q.offer(new int[]{newPos, dist + 1});
                }
            }
        }
        
        return -1;
    }
}
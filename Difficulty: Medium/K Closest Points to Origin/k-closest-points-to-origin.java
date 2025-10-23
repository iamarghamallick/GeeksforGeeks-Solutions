class Pair {
    double dist;
    int point[];
    Pair(double dist,int point[]){
        this.dist = dist;
        this.point = new int[point.length];
        for(int i = 0;i<point.length;i++)
            this.point[i]=point[i];
    }
}

class Solution {
    public ArrayList<ArrayList<Integer>> kClosest(int[][] points, int k) {
        PriorityQueue<Pair> minHeap= new PriorityQueue<>((a,b) -> Double.compare(a.dist,b.dist));
        for(int i[]:points) {
            double eDist = (double)i[0] * i[0] + i[1] * i[1];
            minHeap.add(new Pair(Math.sqrt(eDist),i));
        }
        
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        while(k-- != 0){
            ArrayList<Integer> temp = new ArrayList<>();
            Pair p = minHeap.poll();
            if(p.point.length == 2){
                temp.add(p.point[0]);
                temp.add(p.point[1]);
            }
            ans.add(temp);
        }
        return ans;
    }
}
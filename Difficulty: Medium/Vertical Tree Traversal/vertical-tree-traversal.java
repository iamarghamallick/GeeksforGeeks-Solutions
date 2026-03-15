/*
class Node {
    int data;
    Node left;
    Node right;

    Node(int data) {
        this.data = data;
        left = null;
        right = null;
    }
}
*/

class Solution {
    static class Segment{
        Node n;
        int v;
        int h;
        Segment(Node n,int v,int h){
            this.n=n;
            this.v=v;
            this.h=h;
        }
    }
    static ArrayList<ArrayList<Integer>> verticalOrder(Node root) {
        // add your code here
        Queue<Segment> q=new LinkedList<>();
        HashMap<Integer,ArrayList<Integer>> m=new HashMap<>();
        ArrayList<ArrayList<Integer>> res=new ArrayList<>();
        if(root==null) return res;
        q.add(new Segment(root,0,0));
        while(!q.isEmpty()){
            int l=q.size();
            for(int i=0;i<l;i++){
                Segment cur=q.poll();
                if(m.containsKey(cur.v)){
                    ArrayList<Integer> d=m.get(cur.v);
                    d.add(cur.n.data);
                    m.put(cur.v,d);
                }else{
                    ArrayList<Integer> d=new ArrayList<>();
                    d.add(cur.n.data);
                    m.put(cur.v,d);
                }
                if(cur.n.left!=null){
                    q.offer(new Segment(cur.n.left,cur.v-1,cur.h+1));
                }
                if(cur.n.right!=null){
                    q.offer(new Segment(cur.n.right,cur.v+1,cur.h+1));
                }
            }
        }
        int[] a=new int[m.size()];
        int e=0;
        for(int k:m.keySet()){
            a[e++]=k;
        }
        Arrays.sort(a);
        for(int i=0;i<a.length;i++){
            res.add(m.get(a[i]));
        }
        return res;
    }
}
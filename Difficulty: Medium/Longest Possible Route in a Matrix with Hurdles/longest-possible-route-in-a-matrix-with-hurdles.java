class Solution {
    public int pathLength(int [][] mat, int cx, int cy, int xd, int yd, boolean [][] visited){
        if(cx == xd && cy == yd) return 0;
        int count = -1;
        visited[cx][cy] = true;
        
        if(cx + 1 < mat.length && !visited[cx+1][cy] && mat[cx+1][cy] == 1){
            int temp = pathLength(mat,cx+1,cy,xd,yd,visited);
            if(temp != -1){
                count = Integer.max(count,temp+1);
            }
        }
        if(cx - 1 >= 0 && !visited[cx-1][cy] && mat[cx-1][cy] == 1){
            int temp = pathLength(mat,cx-1,cy,xd,yd,visited);
            if(temp != -1){
                count = Integer.max(count,temp+1);
            }
        }
        if(cy + 1 < mat[0].length && !visited[cx][cy+1] && mat[cx][cy+1] == 1){
            int temp = pathLength(mat,cx,cy+1,xd,yd,visited);
            if(temp != -1){
                count = Integer.max(count,temp+1);
            }
        }
        if(cy - 1 >= 0 && !visited[cx][cy-1] && mat[cx][cy-1] == 1){
            int temp = pathLength(mat,cx,cy-1,xd,yd,visited);
            if(temp != -1){
                count = Integer.max(count,temp+1);
            }
        }
        
        visited[cx][cy] = false;
        return count;
    }
    
    public int longestPath(int[][] mat, int xs, int ys, int xd, int yd) {
        // code here
        int n = mat.length;
        int m = mat[0].length;
        boolean [][] visited = new boolean [n][m];
        return pathLength(mat,xs,ys,xd,yd,visited);
    }
}
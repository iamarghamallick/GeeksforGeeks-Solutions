class Solution {
    public int orangesRot(int[][] mat) {
        int freshCounts = 0;
        Queue<int[]>  q = new LinkedList<>();
        int m = mat.length;
        int n = mat[0].length;

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 1){
                    freshCounts++;
                }else if(mat[i][j] == 2){
                    q.add(new int[]{i,j});
                }
            }
        }
        if(freshCounts == 0){
            return 0;
        }

        int time = 0;

        while(!q.isEmpty()){

            int size = q.size();

            for(int i = 0 ; i < size ; i++){
                int[] rottenLoc = q.remove();
                int r = rottenLoc[0];
                int c = rottenLoc[1];

                int[][] neighbors = {{r-1,c},{r,c+1},{r+1,c},{r,c-1}};
                for(int[] neighbor : neighbors){
                    int nr = neighbor[0];
                    int nc = neighbor[1];
                    //neighbor out of bound or 
                    if(nr < 0 || nr >= m || nc < 0 || nc >= n || mat[nr][nc] == 2 || mat[nr][nc] == 0){
                        continue;
                    }
                    q.add(new int[]{nr,nc});
                    mat[nr][nc] = 2;
                    freshCounts--;
                    if(freshCounts == 0){
                        return time+1;
                    }
                }
            }
            time++;
        }
        return -1;
    }
}
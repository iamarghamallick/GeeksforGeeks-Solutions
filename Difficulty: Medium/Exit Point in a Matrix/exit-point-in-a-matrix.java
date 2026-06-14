class Solution {
    public List<Integer> exitPoint(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        int[][] dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        List<Integer> ans = new ArrayList<>();
        int i = 0, j = 0, dir = 0;
        while(i < n && j < m) {
            if(mat[i][j] == 1) {
                dir = (dir + 1) % 4;
                mat[i][j] = 0;
            }
            int ni = i + dirs[dir][0];
            int nj = j + dirs[dir][1];
            if(ni < 0 || ni >= n || nj < 0 || nj >= m) {
                ans.add(i);
                ans.add(j);
                break;
            }
            i = ni;
            j = nj;
        }
        return ans;
    }
}
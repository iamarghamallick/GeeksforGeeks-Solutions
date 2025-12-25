class Solution {
    public ArrayList<Integer> findPeakGrid(int[][] mat) {
        ArrayList<Integer> ans = new ArrayList<>();
        int i = 0;
        int j = mat[0].length - 1;
        while(i<mat.length && j>=0) {
            int top = i-1 >= 0 ? mat[i-1][j] : Integer.MIN_VALUE;
            int bottom = i+1 < mat.length ? mat[i+1][j] : Integer.MIN_VALUE;
            int left = j-1 >= 0 ? mat[i][j-1] : Integer.MIN_VALUE;
            int right = j+1 < mat[0].length ? mat[i][j+1] : Integer.MIN_VALUE;
            
            if(mat[i][j] < top) i--;
            else if(mat[i][j] < bottom) i++;
            else if(mat[i][j] < left) j--;
            else if(mat[i][j] < right) j++;
            else {
                ans.add(i);
                ans.add(j);
                return ans;
            }
        }
        return ans;
    }
}
class Solution {
    public ArrayList<ArrayList<Integer>> transpose(int[][] mat) {
        int n = mat.length;
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        
        for(int i=0; i<n; i++) {
            ArrayList<Integer> temp = new ArrayList<>();
            for(int j=0; j<n; j++)
                temp.add(mat[j][i]);
            ans.add(temp);
        }
        
        return ans;
    }
}
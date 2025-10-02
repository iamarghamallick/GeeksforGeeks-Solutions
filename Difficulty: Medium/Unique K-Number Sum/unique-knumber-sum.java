class Solution {
    private void backtrack(int n, int k, int start, int sum, ArrayList<Integer> curr, ArrayList<ArrayList<Integer>> ans) {
        if(curr.size() == k && sum == n) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        
        for(int num = start; num <= 9; num++) {
            curr.add(num);
            backtrack(n, k, num + 1, sum + num, curr, ans);
            curr.remove(curr.size() - 1);
        }
    }
    
    public ArrayList<ArrayList<Integer>> combinationSum(int n, int k) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> curr = new ArrayList<>();
        backtrack(n, k, 1, 0, curr, ans);
        return ans;
    }
}
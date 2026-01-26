class Solution {
    public static ArrayList<ArrayList<Integer>> permuteDist(int[] arr) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> temp = new ArrayList<>();
        boolean[] visited = new boolean[arr.length];
        permute(visited, arr, temp, ans);
        return ans;
    }
    
    private static void permute(boolean[] visited, int[] arr, ArrayList<Integer> temp, ArrayList<ArrayList<Integer>> ans) {
        if(temp.size() == arr.length) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=0; i<arr.length; i++) {
            if(visited[i] == true) continue;
            visited[i] = true;
            temp.add(arr[i]);
            permute(visited, arr, temp, ans);
            temp.remove(temp.size() - 1);
            visited[i] = false;
        }
    }
};
class Solution {
    private static void backtrack(int[] arr, boolean[] visited, ArrayList<Integer> curr, ArrayList<ArrayList<Integer>> ans) {
        if(curr.size() == arr.length) {
            ans.add(new ArrayList<>(curr));
            return;
        }
        
        for(int i=0; i<arr.length; i++) {
            if(visited[i] || (i > 0 && arr[i] == arr[i-1] && !visited[i-1])) 
                continue;
            
            visited[i] = true;
            curr.add(arr[i]);
            
            backtrack(arr, visited, curr, ans);
            
            curr.remove(curr.size() - 1);
            visited[i] = false;
        }
    }
    
    public static ArrayList<ArrayList<Integer>> uniquePerms(int[] arr) {
        Arrays.sort(arr);
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        ArrayList<Integer> curr = new ArrayList<>();
        boolean[] visited = new boolean[arr.length];
        backtrack(arr, visited, curr, ans);
        return ans;
    }
};
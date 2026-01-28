class Solution {
    public int countSubset(int[] arr, int k) {
        long sum = Arrays.stream(arr).sum();
        if(k > sum) return 0;
        Arrays.sort(arr);
        int n = arr.length;
        Map<List<Integer>, Integer> map = new HashMap<>();
        return f(0, k, arr, map);
    }
    
    private int f(int ind, int target, int[] arr, Map<List<Integer>, Integer> map) {
        if(target == 0) return 1;
        if(target < 0 || ind >= arr.length) return 0;
        
        if(map.containsKey(Arrays.asList(ind, target)))
            return map.get(Arrays.asList(ind, target));
        
        int take = f(ind+1, target-arr[ind], arr, map);
        int notTake = f(ind+1, target, arr, map);
        
        int ans = take + notTake;
        map.put(Arrays.asList(ind, target), ans);
        
        return ans;
    }
}

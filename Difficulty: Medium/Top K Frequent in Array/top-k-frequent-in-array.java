class Solution {
    public ArrayList<Integer> topKFreq(int[] arr, int k) {
        Map<Integer, Integer> freq = new HashMap<>();
        for (int n : arr)
            freq.put(n, freq.getOrDefault(n, 0) + 1);

        List<Map.Entry<Integer, Integer>> list = new ArrayList<>(freq.entrySet());

        list.sort((a, b) -> {
            if (!a.getValue().equals(b.getValue()))
                return b.getValue() - a.getValue();
            return b.getKey() - a.getKey();
        });

        ArrayList<Integer> ans = new ArrayList<>();
        for (int i = 0; i < k && i < list.size(); i++)
            ans.add(list.get(i).getKey());

        return ans;
    }
}

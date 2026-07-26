class Solution {
    public ArrayList<ArrayList<Integer>> levelSort(int[] arr) {
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();

        int n = arr.length;
        int i = 0;
        int lvl = 0;

        while (i < n) {
            ArrayList<Integer> list = new ArrayList<>();

            int len = (int) Math.pow(2, lvl);

            for (int j = 0; j < len && j + i < n; j++) {
                int x = arr[i + j];

                if (x == -1) {
                    continue;
                }

                list.add(x);
            }

            Collections.sort(list);
            ans.add(list);

            i = i + len;
            lvl++;
        }

        return ans;
    }
}
class Solution {
  public ArrayList<Integer> findPairs(int[] arr) {
    int n = arr.length;
    HashMap<Integer, int[]> map = new HashMap<>();
    ArrayList<Integer> ans = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int sum = arr[i] + arr[j];

        if (!map.containsKey(sum)) {
          map.put(sum, new int[] {i, j});
          continue;
        }

        int[] temp = map.get(sum);
        int x = temp[0];
        int y = temp[1];

        if (x == i || x == j || y == i || y == j) {
          continue;
        }

        ArrayList<Integer> curr = new ArrayList<>(List.of(x, y, i, j));

        if (ans.isEmpty() || isSmaller(curr, ans)) {
          ans = curr;
        }
      }
    }

    if (ans.isEmpty()) {
      return new ArrayList<>(List.of(-1, -1, -1, -1));
    }

    return ans;
  }

  private boolean isSmaller(ArrayList<Integer> a, ArrayList<Integer> b) {
    for (int i = 0; i < 4; i++) {
      if (a.get(i) != b.get(i))
        return a.get(i) < b.get(i);
    }

    return false;
  }
}
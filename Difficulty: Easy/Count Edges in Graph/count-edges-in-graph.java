class Solution {
  public int countEdges(ArrayList<ArrayList<Integer>> adj) {
    int count = 0;

    for (int j = 0; j < adj.size(); j++) {
      for (int i : adj.get(j)) {
        if (j < i) {
          count++;
        }
      }
    }

    return count;
  }
}
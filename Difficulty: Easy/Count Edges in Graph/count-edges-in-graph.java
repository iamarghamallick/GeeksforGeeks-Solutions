class Solution {
  public int countEdges(ArrayList<ArrayList<Integer>> adj) {
    return adj.stream().mapToInt(ArrayList::size).sum() / 2;
  }
}
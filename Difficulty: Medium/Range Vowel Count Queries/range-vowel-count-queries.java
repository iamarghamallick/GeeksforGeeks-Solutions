class Solution {
  public ArrayList<Integer> countVowels(String s, int[][] queries) {
    int n = s.length();
    int[] vowels = new int[n];
    ArrayList<Integer> ans = new ArrayList<>();

    for (int i = 0; i < n; i++) {
      if (i == 0) {
        vowels[i] = isVowel(s.charAt(i)) ? 1 : 0;
      } else {
        vowels[i] = vowels[i - 1] + (isVowel(s.charAt(i)) ? 1 : 0);
      }
    }

    for (int[] query : queries) {
      int start = query[0];
      int end = query[1];

      ans.add(vowels[end] - (start == 0 ? 0 : vowels[start - 1]));
    }

    return ans;
  }

  private boolean isVowel(char c) {
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
  }
}
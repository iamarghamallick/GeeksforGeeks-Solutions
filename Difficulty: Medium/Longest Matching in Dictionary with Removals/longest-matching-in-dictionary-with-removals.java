class Solution {
	public String findLongestWord(String s, List<String> d) {
		Collections.sort(d);
		
		List<List<Integer>> map = new ArrayList<>();
		
		for (int i = 0; i<26; i++) {
			map.add(new ArrayList<>());
		}
		
		for (int i = 0; i<s.length(); i++) {
			map.get(s.charAt(i) - 'a').add(i);
		}
		
		String ans = "";
		int maxLen = 0;
		
		for (String word: d) {
			if (word.length() > s.length()) {
				continue;
			}
			
			if (isValid(word, map)) {
				if (word.length() > maxLen) {
					maxLen = word.length();
					ans = word;
				}
			}
		}
		
		return ans;
	}
	
	private boolean isValid(String word, List<List<Integer>> map) {
		int prev = -1;
		
		for (char ch: word.toCharArray()) {
			List<Integer> pos = map.get(ch - 'a');
			
			int it = -1;
			
			for (int i = 0; i<pos.size(); i++) {
				if (pos.get(i) > prev) {
					it = pos.get(i);
					break;
				}
			}
			
			if (it == -1) {
				return false;
			}
			
			prev = it;
		}
		
		return true;
	}
}

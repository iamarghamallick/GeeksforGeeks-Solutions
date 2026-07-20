class Solution {
    class Node {
        Node[] children;
        int frequency;

        Node() {
            children = new Node[26];
            frequency = 0;
        }
    }

    Node trieRoot = new Node();

    private void addWord(String word) {
        Node currentNode = trieRoot;

        for (char character : word.toCharArray()) {
            int position = character - 'a';

            if (currentNode.children[position] == null) {
                currentNode.children[position] = new Node();
            }

            currentNode = currentNode.children[position];
            currentNode.frequency++;
        }
    }

    private String findUniquePrefix(String word) {
        Node currentNode = trieRoot;
        StringBuilder prefix = new StringBuilder();

        for (char character : word.toCharArray()) {
            int position = character - 'a';
            currentNode = currentNode.children[position];
            prefix.append(character);

            if (currentNode.frequency == 1) {
                break;
            }
        }

        return prefix.toString();
    }

    public ArrayList<String> findPrefixes(String[] words) {

        for (String word : words) {
            addWord(word);
        }

        ArrayList<String> result = new ArrayList<>();

        for (String word : words) {
            result.add(findUniquePrefix(word));
        }

        return result;
    }
}
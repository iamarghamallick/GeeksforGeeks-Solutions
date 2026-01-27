class Solution {
    public boolean isWordExist(char[][] mat, String word) {

        for (int i = 0; i < mat.length; i++) {
            for (int j = 0; j < mat[0].length; j++) {

                if (mat[i][j] == word.charAt(0)) {
                    if (find(mat, i, j, 0, word)) {
                        return true;
                    }
                }

            }
        }

        return false;
    }

    private boolean find(char[][] mat, int row, int col, int idx, String word) {

        // If all characters are matched
        if (idx == word.length()) {
            return true;
        }

        int n = mat.length;
        int m = mat[0].length;

        // Boundary check
        if (row < 0 || col < 0 || row >= n || col >= m) {
            return false;
        }

        // Character mismatch
        if (mat[row][col] != word.charAt(idx)) {
            return false;
        }

        // Mark current cell as visited
        char temp = mat[row][col];
        mat[row][col] = '#';

        boolean result =
                find(mat, row + 1, col, idx + 1, word) ||
                find(mat, row - 1, col, idx + 1, word) ||
                find(mat, row, col + 1, idx + 1, word) ||
                find(mat, row, col - 1, idx + 1, word);

        // Restore cell
        mat[row][col] = temp;

        return result;
    }
}
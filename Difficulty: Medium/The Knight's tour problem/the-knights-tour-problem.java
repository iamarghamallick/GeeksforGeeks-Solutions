class Solution {
    public ArrayList<ArrayList<Integer>> knightTour(int n) {
        ArrayList<ArrayList<Integer>> board = new ArrayList<>(n);
        for (int i = 0; i < n; i++)
            board.add(new ArrayList<>(Collections.nCopies(n, -1)));

        board.get(0).set(0, 0);

        if (solve(0, 0, 1, n, board))
            return board;

        return new ArrayList<>();
    }

    private boolean solve(int x, int y, int move, int n, ArrayList<ArrayList<Integer>> board) {
        if (move == n * n)
            return true;

        int[][] dirs = {
            {-2, -1}, {-2, 1}, {-1, -2}, {1, -2},
            {2, -1}, {2, 1}, {-1, 2}, {1, 2}
        };

        for (int[] dir : dirs) {
            int nx = x + dir[0];
            int ny = y + dir[1];

            if (nx >= 0 && ny >= 0 && nx < n && ny < n && board.get(nx).get(ny) == -1) {
                board.get(nx).set(ny, move);
                if (solve(nx, ny, move + 1, n, board))
                    return true;
                board.get(nx).set(ny, -1);
            }
        }

        return false;
    }
}
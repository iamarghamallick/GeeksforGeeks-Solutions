class Solution {
    static boolean isSquare(int x) {
        int sqRoot = (int) Math.sqrt(x);
        return (sqRoot * sqRoot == x);
    }
    
    public int minSquares(int n) {
        if (isSquare(n)) return 1;
        for (int i = 1; i * i <= n; i++)
            if (isSquare(n - (i * i)))
                return 2;
        while (n > 0 && n % 4 == 0) n /= 4;
        if (n % 8 == 7) return 4;
        return 3;
    }
}
class Solution {
  static final long MOD = 1000000007L;

  public int minTime(int a, int b, int d, int l, int r) {
    long t1 = solve(a, b, l, d);
    long t2 = solve(a, b, r + 1, d);

    return (int)((prefix(a, b, t1) - prefix(a, b, t2) + MOD) % MOD);
  }

  private long solve(int a, int b, int c, int d) {
    int remaining = d - c;

    if (remaining <= 0)
      return 1;

    if (remaining <= a)
      return remaining + 1;

    int net = a - b;
    long distance = remaining - a;
    long cycles = (distance + net - 1) / net;

    return remaining + 2L * b * cycles + 1;
  }

  private long prefix(int a, int b, long t) {
    long total = (t % MOD) * ((t + 1) % MOD) % MOD;
    total = total * ((MOD + 1) / 2) % MOD;

    return (total - summ(a, b, t) + MOD) % MOD;
  }

  private long summ(int a, int b, long t) {
    long first = a + 2;
    long cycleTime = a + b;

    if (t < first)
      return 0;

    long count = (t - first) / cycleTime + 1;
    long last = first + (count - 1) * cycleTime;

    long term1 = (b % MOD) * (count % MOD) % MOD;
    term1 = term1 * ((first + last) % MOD) % MOD;

    long term2 = (count % MOD) * (2L * b - 1) % MOD;
    term2 = term2 * (2L * b) % MOD;
    term2 = term2 * ((MOD + 1) / 2) % MOD;

    return (term1 + term2) % MOD;
  }
}
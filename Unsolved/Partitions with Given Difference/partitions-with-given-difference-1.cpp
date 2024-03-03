// PROBLEM LINK: https://www.geeksforgeeks.org/problems/partitions-with-given-difference/1

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int MOD = (int)1e9 + 7;

    int countPartitions(int n, int d, vector<int> &arr)
    {
        // Code here
        int sum = 0;
        for (int i = 0; i < n; i++)
            sum += arr[i];

        // corner cases
        if (d > sum)
            return 0;
        if ((d + sum) % 2 != 0)
            return 0;

        // this is the subset sum problem with sum as follows
        sum = (d + sum) / 2;

        // initializing the dp array
        int dp[n + 1][sum + 1];

        for (int j = 0; j <= sum; j++)
            dp[0][j] = 0;
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= sum; j++)
            {
                if (arr[i - 1] <= j)
                {
                    dp[i][j] = (dp[i - 1][j - arr[i - 1]] + dp[i - 1][j]) % MOD;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j] % MOD;
                }
            }
        }

        return dp[n][sum];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, d;
        cin >> n >> d;
        vector<int> arr;

        for (int i = 0; i < n; ++i)
        {
            int x;
            cin >> x;
            arr.push_back(x);
        }

        Solution obj;
        cout << obj.countPartitions(n, d, arr) << "\n";
    }
    return 0;
}
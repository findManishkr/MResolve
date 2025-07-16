#include <iostream>
#include <vector>

using namespace std;

const int mod = 1e9 + 7;

int countWays(int x, vector<int>& coins) {
    int numCoins = coins.size();

    vector<int> dp(x + 1, 0);
    dp[0] = 1; 

   
    for (int i = 1; i <= x; i++) {
        for (int j = 0; j < numCoins; j++) {
            if (i - coins[j] >= 0) {
                
                dp[i] = (dp[i] + dp[i - coins[j]]) % mod;
            }
        }
    }

    return dp[x];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int numCoins, targetSum;
    cin >> numCoins >> targetSum;

    vector<int> coins(numCoins);
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    cout << countWays(targetSum, coins) << endl;

    return 0;
}

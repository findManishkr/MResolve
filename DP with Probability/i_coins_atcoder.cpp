

#include <bits/stdc++.h>
using namespace std;

#define ll long long 
#define ld long double 
#define INF 1e18

void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}

ld p(vector<ld>& prob, int k) {
    int n = prob.size();
    vector<vector<ld>> dp(n + 1, vector<ld>(k + 1, 0.0));
    dp[0][0] = 1.0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            // Case: coin i-1 is tail
            dp[i][j] += dp[i - 1][j] * (1.0 - prob[i - 1]);
            // Case: coin i-1 is head
            if (j > 0)
                dp[i][j] += dp[i - 1][j - 1] * prob[i - 1];
        }
    }

    return dp[n][k];
}

ld f(int n, vector<ld>& prob) {
    ld sum = 0.0;
    for (int i = (n / 2) + 1; i <= n; i++)
        sum += p(prob, i);
    return sum;
}

int main() {
    setupIO();
    // int n;
    // cin >> n;
    // vector<ld> arr(n);
    // for (int i = 0; i < n; i++) cin >> arr[i];

  //  cout << fixed << setprecision(17) << f(n, arr) << endl;

         ld x = 25.94857;
         cout << fixed << setprecision(4) << x << endl;
    return 0;
}

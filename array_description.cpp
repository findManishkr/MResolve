#include <bits/stdc++.h>
using namespace std;
void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
const int MOD = 1e9 + 7;
int N, M;
int dp[100005][105];

int f(const vector<int>& arr, int idx, int prev) {
    if (idx == N) return 1;

    if (dp[idx][prev] != -1) return dp[idx][prev];

    int ans = 0;

    if (arr[idx] != 0) {
        if (prev == 0 || abs(arr[idx] - prev) <= 1) {
            ans = f(arr, idx + 1, arr[idx]) % MOD;
        }
    } else {
        // Prune unnecessary values: only try prev-1, prev, prev+1

        int start = (prev == 0) ? 1 : max(1, prev - 1);
        int end = (prev == 0) ? M : min(M, prev + 1);

        for (int val = start; val <= end; ++val) {
            ans = (ans + f(arr, idx + 1, val)) % MOD;
        }
    }

    return dp[idx][prev] = ans;
}

int main() { setupIO();
    

    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << f(arr, 0, 0) << "\n";  // prev = 0 as sentinel value
    return 0;
}

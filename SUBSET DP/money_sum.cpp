/*
https://cses.fi/problemset/task/1745/

*/



#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define INF 1e18
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
int dp[105][100005];
set<int>s;
void f( vector <int>&coin, int idx, int sum ){
        if( idx >= coin.size()){
              if(sum > 0 ) s.insert( sum);
               return ;
        }
           if( dp[idx][sum] == 1)  // if(idx,sum )th state is already visited, then don't visit it
               return;
                dp[idx][sum] = 1;      // if( idx,sum)th state is unvisited, then marked it visited,
        f(coin,  idx+1, coin[idx]+ sum );
        f( coin, idx+1, sum);
}
int main(){ setupIO();

    int N;
    cin >> N;
    vector<int>coin(N);
    for( int i = 0; i < N; i++)
        cin >> coin[i];

      s.clear();
    
     f(coin, 0, 0);
     cout << s.size() <<'\n';
     for( auto &el : s)
     cout << el <<' ';

    return 0;
}
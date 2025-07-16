/*
https://atcoder.jp/contests/dp/tasks/dp_d

concept : 0/1 knapsack

*/




#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define INF 1e18
#define S second
#define F first
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}


 
// top down solution


ll dp[105][100005];
ll f( ll idx, ll curr_wt, vector<pair<ll,ll>>&v){
        // base case
        if( idx >= v.size())
           return 0;
            if( dp[idx][curr_wt] != -1) return dp[idx][curr_wt];
           // if he skips the avail wt and val
      ll skip = f( idx + 1, curr_wt , v);
        // if he takes the avail wt and val in knapsack ( curr wt >= avail wt)
      ll take =  curr_wt >= v[idx].F ?  v[idx].S + f(idx + 1, curr_wt - v[idx].F , v)  : 0;   

      return  dp[idx][curr_wt] = max( skip, take);
        
}



// bottom up solution


ll fbu(  vector <pair <ll,ll>>&vec, ll W, ll N){
    
        vector < vector < ll >>dp(N+1, vector <ll>(W+1, 0));
          for( ll i = N - 1 ; i >= 0; i--){
              for( ll j = 0 ; j <= W; j++){
                    // ll skip = dp[i+1][j];
                    // ll take = (j >= vec[i].F) ? vec[i].S + dp[i+1][j - vec[i].F] : 0;
                    dp[i][j] = max(dp[i+1][j], (j >= vec[i].F) ? vec[i].S + dp[i+1][j - vec[i].F] : 0);
              }
          }
         
          return dp[0][W];
}

ll fbu_optimized(vector<pair<ll, ll>>& vec, ll W, ll N) {
    vector<ll> dp(W + 1, 0);

    for (ll i = 0; i < N; i++) {
        for (ll j = W; j >= vec[i].first; j--) {
            dp[j] = max(dp[j], vec[i].second + dp[j - vec[i].first]);
        }
    }
    return dp[W];
}



// space optimized bottom up



int main(){ setupIO();
  ll N, W;
  cin >> N >> W;
   vector< pair <ll,ll>> vec;

  for( ll i = 0; i < N; i++){
       ll w, v;
       cin >> w >> v;
       vec.push_back({w,v});
  }

//    memset(dp, -1, sizeof(dp));
  // cout << f(0,W,vec) <<'\n';
  cout <<fbu(vec,W,N) <<'\n';
//  cout <<fbu_optimized(vec,W,N) <<'\n';


    return 0;
}
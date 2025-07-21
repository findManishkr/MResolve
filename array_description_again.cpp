#include <bits/stdc++.h>
using namespace std;

void setupIO() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
}
int N , M;
const int mod = 1e9 + 7;
int dp[100005][105];

int f( vector <int>&arr, int idx, int prev ){
      if( idx == N ) return 1;    // ie valid solution has been found

       if( dp[idx][prev] != -1) return dp[idx][prev];

      int ans = 0;

      if( arr[idx] != 0){

          if( prev == 0 ||  abs( arr[idx] - prev)  <= 1 ) 
          ans =  ( 0 + f( arr, idx + 1, arr[idx]) )  % mod ;
      }else {
        // try out all possible combinations from range [1, m];

        for( int val = 1; val <= M ; val++){

           if( prev == 0 ||  abs( val - prev)  <= 1 ) 
            ans = (  ans + f( arr, idx + 1, val ) ) % mod ;
        }


      }


   return  dp[idx][ prev] = ans;
}

int main() { setupIO();

cin >> N >> M;

vector <int >arr(N);
for( int i = 0;i < N; i++) cin >> arr[i];

memset( dp, -1 ,sizeof( dp ));

cout << f( arr, 0, 0);    //  set 0 as sentinal value instead of -1, due to indexing problem
  
    return 0;
}

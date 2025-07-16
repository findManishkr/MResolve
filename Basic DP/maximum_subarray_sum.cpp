
#include <bits/stdc++.h>
using namespace std;
#define ninf INT_MIN

const int N = 1e5 + 5;
vector < vector <int>> dp;
int f( int idx, bool mustPicked, vector <int>&arr){
        if( idx  >= arr.size()) return mustPicked ? 0 : ninf ;
          if( dp[idx][mustPicked] != ninf) return dp[idx][mustPicked];
          int MoveNext = arr[idx] +  f( idx + 1, 1, arr);
          int Skip = f( idx + 1, 0, arr);  
     return dp[idx][mustPicked] =  mustPicked ? max(MoveNext,0) : max(MoveNext, Skip);
}
// int fbu ( int n, vector <int >&arr){
//     vector < vector <int>> dp( n+1, vector <int>(2,ninf));

// }
void solve(){
     int n; cin >>n;
     vector <int > arr(n);
     for ( int &el: arr ) cin >> el;
       dp.clear();
       dp.resize( N, vector <int>(2,ninf) );
       
     cout << f(0,0,arr) <<'\n';
     for ( int i = 0; i < n; i++){
        cout << dp[i][0] <<" " <<  dp[i][1];
        cout << '\n';

     }

}


int main() {
   
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin); 
freopen("output.txt", "w", stdout);
#endif
    
  int T;
  cin >> T;
  while(T--){
    solve();
  }
    return 0;
}




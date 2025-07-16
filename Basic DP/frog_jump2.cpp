/*
https://atcoder.jp/contests/dp/tasks/dp_b

*/

/*--------------: top - down solution : --------
#include <bits/stdc++.h>
using namespace std;
#define inf  INT_MAX
  vector<int>h;
  int k;
  vector<int>dp;
int f( int i ){  // returns min cost to reach n-1 th idx from idx 0
      // base case 
     if( i  >= h.size())  return inf ;
     if( i == h.size() -1 ) return 0;

     if(dp[i] != -1) return dp[i];    // ie that state is already calulated else calculate

            int ans = inf;
        for( int j = 1; j <= k ;j++){
         if( i + j <= h.size()-1){ 
           ans = min( ans, f(i+j) + abs( h[i+j]-h[i]) );
         }
        
      }
          
   return dp[i] = ans;
}
int main(){
    int n;
     cin >> n >> k;
     h.resize(n);
     for( int i = 0; i < n; i++) cin >> h[i];

      dp.clear();
      dp.resize(n,-1);
     cout << f( 0) <<'\n';
    return 0;
}

*/

//-----------bottoum-up solution

#include <bits/stdc++.h>
using namespace std;
#define inf  INT_MAX

int bottomUp( vector<int>&h ,int n,int k){
    vector<int>dp(n,inf);

    dp[n-1] = 0;
    dp[n-2] = abs( h[n-2] - h[n-1]);

    for( int i = n-3; i >= 0; i--){
         for( int j = 1; j <= k ;j++){
             if( i + j > n -1) continue;   // or break;
           dp[i] = min( dp[i+j] + abs(h[i+j] - h[i]), dp[i])  ;

         }
    }
return dp[0];

}
int main(){
   int n , k;
    cin >> n >> k;
    vector<int>h(n);
    for( int i = 0; i < n; i++) cin >> h[i];


    cout <<bottomUp(h,n,k) <<'\n';
    return 0;
}

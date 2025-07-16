/*
 link : https://cses.fi/problemset/task/1634

*/

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int N = 1e6+5;
int inf = INT_MAX;

 int n , x;
  vector<int>c;
//    vector<int>memo(N,-1);
// int f( int x ){
//     if( x <= 0) return 0;

//      if( memo[x] != -1)  return memo[x] ;        // xth state is already computed , else compute
// 	      int res = inf;

//      for( int j = 0; j < (int)c.size(); j++)  {
//           if( (x - c[j]) >= 0){
//              res = min(res, f( x - c[j]) );
//           }
//      }
//      return  memo[x] =  res != inf ?  1 + res : inf;
// }
int bottomUp(int x){

    if( x == 0) return 0;

      vector<int>tab(x+1,inf);
           tab[0]  = 0;
        for( int i = 1; i <= x; i++){
              int res = inf;
            for( int j = 0; j < c.size(); j++)
                if( (i - c[j]) >= 0){
                     res = min(res, tab[i - c[j] ]);
                }

               tab[i] =   res != inf ? 1 + res : inf  ;

        }

        //    for( int i = 1; i <= x; i++){
            
        //     for( int j = 0; j < c.size(); j++)
        //         if( (i - c[j]) >= 0){
        //              tab[i] = min(tab[i], tab[i - c[j] ]);
        //         }

        //        tab[i] =   tab[i] != inf ? 1 + tab[i] : inf  ;

        // }

    return tab[x] == inf ? -1 : tab[x];
}
int main(){

    cin >> n >> x;
    c.resize(n);

    for( int i = 0; i < n;i++) cin >> c[i];
    
          // cout << (f(x) != inf ? f(x) : -1 )<< '\n'; 

        cout << bottomUp(x) <<'\n';

      return 0;

}



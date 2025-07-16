/*
https://www.spoj.com/problems/TOURIST/

topic : state reduction 

*/


#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
int n, m;
char arr[105][105];
// since out of 4 states there is constitutive relation 
//     x +y = i +j      // this can be easily reduced into 3 states parameter
int dp[102][102][102];
int f( int i, int j, int x, int y){
        if( i >= m || j >= n || x >= m || y >= n || arr[i][j] == '#' || arr[x][y] == '#' )
        return 0;

        if( i == m-1 && j == n -1 )
             return arr[i][j] == '*' ;
        
          if( dp[i][j][x] != -1) return dp[i][j][x]; /// ie (i,j,x)th state is already computed, else compute   
        int res = -inf;
        res = max( res, f(i+1, j, x+1, y) );
        res = max( res, f(i, j+1, x, y+1) );
        res = max( res, f(i, j+1, x+1, y) );  
        res = max( res, f(i+1, j, x, y+1) );  
        
         res += ( arr[i][j] == '*');
         res += ( arr[x][y] == '*');

        // what if they are stanging at same location
        if( (i == x && j == y) &&( arr[i][j] == '*') )
              res--;
        
          return dp[i][j][x] = res;
    }
int main(){ setupIO();
 int T;
 cin >> T;
  while(T--){

     cin >> n >> m;
          memset(dp , -1 ,sizeof(dp));
     for( int i = 0; i < m; i++){
         for( int j = 0; j < n; j++)
          cin >> arr[i][j];
     }

      cout << f( 0,0,0,0) <<'\n';
  }
 
    return 0;
}

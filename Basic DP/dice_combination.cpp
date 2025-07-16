/*
https://cses.fi/problemset/task/1633

*/


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int inf = INT_MAX;
int N = 1e6+5;
vector<ll>memo(N,-1);
/*
   time : O(N);
   space :O(N);

*/
int f( int n){           // f counts the no of ways to construct sum n;
   if( n == 0) return 1;

         int res = 0;

       if(memo[n] != -1 ) return memo[n];
     for( int j = 1; j <= min(n,6); j++){
     	 //   if( n - j >= 0)
     	 	res =  (res % mod +  f(n-j) % mod)%mod;
     	
     }

return memo[n] = res % mod;
}

int main(){
   int n;
   cin >> n;


 //cout << f(n) <<'\n';
   cout << bottomUp <<'\n';

	return 0;
}
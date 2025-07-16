/*
https://www.spoj.com/problems/GNYR09F/

*/


#include <iostream>
#include <cstring>  // for memset
#include <vector>
using namespace std;


#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

int dp[105][105][2];

int f(int n, int k,int last){
    // base case
    if (n == 1) return (k == 0 ? 1 : 0);
    if (k < 0) return 0;  // Invalid case

     if( dp[n][k][last] != -1) return  dp[n][k][last];  // ie (n,k,last)th state is already computed, else compute
    if( last == 1)
        return dp[n][k][1] = f(n-1,k-1,1) + f(n -1,k, 0);
    
    return  dp[n][k][0] = f(n-1,k, 1)+ f(n-1,k,0);
}
int main(){ SETUP_IO
int t;
cin >> t;
while(t--){

    int i , n , k;
    cin >> i >> n >> k;
  
    memset(dp,-1,sizeof(dp));

    cout << i <<' ' << f(n, k , 0) + f(n, k, 1) <<'\n';
}

    return 0;
}



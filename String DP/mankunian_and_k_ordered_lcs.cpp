/*

https://www.hackerearth.com/problem/algorithm/mancunian-and-k-ordered-lcs-e6a4b8c6/?purpose=login&source=problem-page&update=google

*/
// top down solution

/*

#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

int M, N, K;
vector<vector<vector<int>>> dp;


int f(int i, int j, int k,    vector <int >&s,    vector <int >&t) {
    // Base cases
    if (i >= M || j >= N) return 0;  // Out-of-bounds case
         int res = 0;

     if( dp[i][j][k] != -1) return dp[i][j][k] ;     // ie (i,j,k) th state is already computed, else compute

    if(s[i] == t[j]){
        return dp[i][j][k] =  1 +  f(i+1,j+1, k, s,t);
    }
          if( k > 0 )
            res = 1 +  f(i+1,j+1, k-1, s,t);
          
              res =  max( res , max( f(i+1,j,k,s,t), f(i,j+1,k,s,t)));
        
    
  
    return dp[i][j][k] = res;
}

int main() {  
    SETUP_IO;

     cin >> M >> N >> K;

     vector <int >s(M);
     for( int i = 0; i < M;i++)
     cin >> s[i];
     
     vector <int >t(N);
     for( int i = 0; i < N;i++)
     cin >> t[i];




 

    dp.assign(M + 1, vector<vector<int>>(N + 1, vector<int>(6, -1)));

    cout << f(0, 0, K, s, t) << '\n';

    return 0;
}

*/



#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif


int M, N, K;


int bottomUp( vector <int >&s,vector <int >&t){
    vector<vector<vector<int>>> dp( M,vector<vector<int>>(N, vector<int>(K,0)) );
               int res = 0;
       for( int i = M -1; i >= 0; i--){
          for( int j = N -1; j >= 0; j--){
              for( int k = 0; k < K; k++){
                   if(s[i] == t[j]){
                    dp[i][j][k] = 1 + dp[i+1][j+1][k-1];
                   }else{
                       if( k > )
                   }
              }
          }
       }
}   

int main() {  
    SETUP_IO;

     cin >> M >> N >> K;

     vector <int >s(M);
     for( int i = 0; i < M;i++)
     cin >> s[i];
     
     vector <int >t(N);
     for( int i = 0; i < N;i++)
     cin >> t[i];




 

  //  dp.assign(M + 1, vector<vector<int>>(N + 1, vector<int>(6, -1)));

    cout << f(0, 0, K, s, t) << '\n';

    return 0;
}



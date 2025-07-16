

#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int N = 1e6 + 5;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

//--------------top- down solution ////////////////


    //-------------------bottom up solution------------------------------


 char f( int i, int h){
       // base case
        if( i % 2 == 0 && h == 0) return 'B';
        else if( i % 2 != 0 && h == 0) return 'A';

        
         
 }   
int main(){ SETUP_IO
        int k , l , m;
        cin >> k >> l >> m;
         vector<int>tower(m);
         for( int i = 0; i < m; i++) cin >> tower[i];
     

      
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

int f(int n){
     if( n == 1 ) return 2;
     if( n == 2) return 3;

     return f(n-1) + f(n-2);
}
int main(){     SETUP_IO;
    int n;
     cin >> n;
    
     cout << f( n) <<'\n';
    
    return 0;
}
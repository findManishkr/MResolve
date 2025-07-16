/*
 problem statement:
 given N friends, each one can remain single or can be paired with some other friend only
 once. find out total no of ways friends can remain single or can be paired up


*/



#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif

int f(int n){    
       if( n <= 2) return n ;
    
     return f(n-1) +  (n- 1) * f(n-2);
}
int main(){     SETUP_IO;
    int n;
     cin >> n;
    
     cout << f( n) <<'\n';
    
    return 0;
}
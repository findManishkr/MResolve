
#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 1e18

#define S second
#define F first
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
int f( string s, int idx, int n){
     if( idx >= n-1  ) return 1;
     if( ((s[idx]-'0') * 10 + (s[idx+1] -'0') )  > 26) return 0;
    return f(s, idx+1,n) + f(s, idx+2 ,n);
}
int main(){ setupIO();
     string s;
     cin >> s;
   
     cout << f(s, 0, s.size());

    return 0;
}
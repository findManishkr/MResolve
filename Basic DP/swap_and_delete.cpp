
#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
int N = 1e6 + 5;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
void solve(){
    string s;
    cin >> s;
    int cnt0 = 0, cnt1 = 0;

    for(char ch: s){
     if( ch =='0')  cnt0++;
     else cnt1++;
    }
             int i = 0;
           while(   ( cnt0 > 0 && cnt1 > 0 )){
                 if( s[i] == '0') cnt1--;
                 else cnt0--;
                 i++;
           }

           cout << s.size()- max(cnt0,cnt1) <<'\n';
}
int main(){ SETUP_IO
       
    int t;
    cin >> t;
    while(t--) solve();
      
    return 0;
}
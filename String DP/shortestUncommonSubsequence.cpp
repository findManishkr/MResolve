#include <bits/stdc++.h>
using namespace std;
void setupIO() {
    ios::sync_with_stdio(false);  cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
    #endif
}
#define inf INT_MAX
int M, N;

int f( string &s, string &t,int i, int j){
          if( i >= M) return inf;
          if( j >= N) return 1;
          
       /// find that  matching character (s[i]) in stirng t
         int k;
         for( k = j ; k < N; k++){
              if(s[i] == t[k]) break; /// ie s[i] is found on kth position in string t // else s[i] doest not exit in t
         }
          if( k == N) return 1;

          // if found , 2 choices either pick that character or not pick
          int pick = 1 + f(s,t ,i+1,k+1);
          int left = f(s,t,i+1, j);

       return min(pick, left);
}
int main() {    setupIO();
   string s, t;
   cin >> s >> t;

   M = s.size();
   N = t.size();
  int res = f(s,t,0,0);
  
  cout << ( res < inf ? res : -1);


   return 0;
}

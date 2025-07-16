
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
 vector < vector < string >> dp;
 string f( int i, int j, string &s, string &t){
     
         

   if( i >= s.size() || j >= t.size()) return "";
      
   if( dp[i][j] != "#") return dp[i][j];     // ie (i,j)th state is already computed, else computed
    if( s[i] == t[j]){
        
          return  dp[i][j] = s[i] +  f(i+1,j+1,s,t);
  
    }
    else {
        string a = f(i+1,j,s,t);
        string b = f(i,j+1,s,t);
        return dp[i][j] =  a.size() > b.size() ? a : b; 
    }
}


int main() {  SETUP_IO;
 string s, t;
 cin >> s >> t;
 int M = s.size();
 int N = t.size();
    
    dp.clear();
    dp.resize(M+1, vector<string>(N+1,"#") );
 cout << f(0,0,s,t) << '\n';
  
}

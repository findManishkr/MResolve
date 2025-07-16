
#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
#define SETUP_IO freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
#define SETUP_IO
#endif
 string str = "";
 vector < vector < int >> dp;
 int f( int i, int j, string &s, string &t, string output){
       if( output.size() > str.size()) str = output;
         

   if( i >= s.size() || j >= t.size()) return 0;
      
   if( dp[i][j] != -1) return dp[i][j];     // ie (i,j)th state is already computed, else computed
    if( s[i] == t[j]){
              output.push_back(s[i]);
          return  dp[i][j] = 1 +  f(i+1,j+1,s,t,output);
          output.pop_back();
    }
    else 
        return dp[i][j] =  max(  f(i+1,j,s,t,output),     f(i,j+1,s,t,output) );
    
}


int main() {  SETUP_IO;
 string s, t;
 cin >> s >> t;
 int M = s.size();
 int N = t.size();
    
    dp.clear();
    dp.resize(M+1, vector<int>(N+1,-1) );
    string output = "";
    f(0,0,s,t,output);
    cout << str << '\n';
}
